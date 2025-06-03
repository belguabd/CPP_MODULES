#include "BitcoinExchange.hpp"


int ft_atoi(const std::string &string)
{

    size_t i = 0;

    size_t res = 0;
    size_t sign = 1;

    for (; i < string.size();)
    {
        if (std::isdigit(string[i]))
            res = string[i] - '0' + (res * 10);
        i++;
    }
    return (res * sign);
}

void BitcoinExchange::parseInput(const std::string &filename)
{
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
        throw std::runtime_error("File not found or cannot be opened.");

    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value")
        throw std::runtime_error("Invalid header format. Expected 'date | value'");

    while (std::getline(inputFile, line))
        parseLine(line);
}

bool checkLineFormat(const std::string &line)
{
    return (!std::isdigit(line[0]) ||
            !std::isdigit(line[1]) ||
            !std::isdigit(line[2]) ||
            !std::isdigit(line[3]) ||
            line[4] != '-' ||
            !std::isdigit(line[5]) ||
            !std::isdigit(line[6]) ||
            line[7] != '-' ||
            !std::isdigit(line[8]) ||
            !std::isdigit(line[9]) ||
            line[10] != ' ' ||
            line[11] != '|' ||
            line[12] != ' ');
}

bool isInvalidDate(int month, int day)
{
    return ((month == 1 && day > 31) ||
            (month == 2 && day > 29) ||
            (month == 3 && day > 31) ||
            (month == 4 && day > 30) ||
            (month == 5 && day > 31) ||
            (month == 6 && day > 30) ||
            (month == 7 && day > 31) ||
            (month == 8 && day > 31) ||
            (month == 9 && day > 30) ||
            (month == 10 && day > 31) ||
            (month == 11 && day > 30) ||
            (month == 12 && day > 31));
}
void BitcoinExchange::parseLine(const std::string &line)
{
    int year, month, day;
    if (line.length() > LENGTH)
    {
        std::string value = line.substr(VALUE);
        std::stringstream ss(value); 
        ss >> this->num;

        if (checkLineFormat(line) || ss.fail() || !ss.eof())
        {
            std::cerr << "Error: bad input => " << line << "\n";
            return;
        }
        year = ft_atoi(line.substr(0, 4));
        month = ft_atoi(line.substr(5, 2));
        day = ft_atoi(line.substr(8, 2));
        if (year < 2009 || month > 12 || day > 31 || !day || !month)
        {
            std::cerr << "Error: bad input => " << line << "\n";
            return;
        }
        if (isInvalidDate(month, day))
        {
            std::cerr << "Error: bad input => " << line << "\n";
            return;
        }
        if (this->num > 1000)
        {
            std::cerr << "Error: too large a number." << "\n";
            return;
        }
        if (this->num < 0)
        {
            std::cerr << "Error: not a positive number." << "\n";
            return;
        }
        
        std::string date = line.substr(0, 10);
        std::map<std::string, double>::iterator it = dateValueMap.lower_bound(date);
        if (it == dateValueMap.end())
        {
            --it;
            std::cout << date << " => " << num << " = " << it->second * num << "\n";
        }
        else if (it->first != date)
        {
            if (it != dateValueMap.begin())
            {
                --it;
                std::cout << date << " => " << num << " = " << it->second * num << "\n";
            }
            else
            {
                std::cerr << "Error: bad input => " << line << "\n";
                return;
            }
        }
        else
        {
            std::cout << date << " => " << num << " = " << it->second * num << "\n";
        }
    }
    else
        std::cerr << "Error: bad input => " << line << "\n";
}

bool IsValidCsv(const std::string &buffer)
{
    return ((std::isdigit(buffer[0]) &&
             std::isdigit(buffer[1]) &&
             std::isdigit(buffer[2]) &&
             std::isdigit(buffer[3]) &&
             buffer[4] == '-' &&
             std::isdigit(buffer[5]) &&
             std::isdigit(buffer[6]) &&
             buffer[7] == '-' &&
             std::isdigit(buffer[8]) &&
             std::isdigit(buffer[9])));
}

void BitcoinExchange::setMap(const std::string &av)
{
    std::ifstream file_name("data.csv");
    std::ifstream input_file(av.c_str());
    if (!file_name.is_open() || !input_file.is_open())
        throw std::invalid_argument("file doesn't exit");
    std::string buffer;
    getline(file_name, buffer);
    while (getline(file_name, buffer))
    {
        if (!IsValidCsv(buffer))
        {
            throw std::invalid_argument("Invalid file!!");
        }
        size_t found = buffer.find(',');
        if (found == std::string::npos)
            throw std::invalid_argument("Invalid file!!");
        long double value;
        try
        {
            std::stringstream ss(buffer.substr(found + 1));
            ss >> value;
            if (ss.fail() || !ss.eof())
                throw std::invalid_argument("Invalid value");
        }
        catch (...)
        {
            throw std::invalid_argument("Invalid value");
        }
        std::string date = buffer.substr(0, DATE);
        dateValueMap[date] = value;

    }
}

void BitcoinExchange::main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cerr << "Usage: " << argv[0] << " <input_file>\n";
        return;
    }
    try
    {
        setMap(argv[1]);
        parseInput(argv[1]);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

BitcoinExchange::BitcoinExchange() : num(0.0), dateValueMap() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : num(other.num), dateValueMap(other.dateValueMap) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        num = other.num;
        dateValueMap = other.dateValueMap;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}