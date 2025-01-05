/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:06:51 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/23 16:21:17 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>

#define DATE 10
#define VALUE 12
using namespace std;

int BitcoinExchange::ft_atoi(const std::string &string)
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

bool isLeapYear(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool validateMonths(const string &line)
{
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());

    if (month == 2 && (day > 29 || (day > 28 && !isLeapYear(year))))
        return (false);
    return !((month == 1 && day > 31) ||
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

bool isValidDateLine(const std::string &line)
{

    if (line.size() < 13)
        return (false);
    long double num;
    std::string value = line.substr(VALUE);
    std::stringstream ss(value);
    ss >> num;

    return (std::isdigit(line[0]) &&
            std::isdigit(line[1]) &&
            std::isdigit(line[2]) &&
            std::isdigit(line[3]) &&
            line[4] == '-' &&
            std::isdigit(line[5]) &&
            std::isdigit(line[6]) &&
            line[7] == '-' &&
            std::isdigit(line[8]) &&
            std::isdigit(line[9]) &&
            line[10] == ' ' &&
            line[11] == '|' &&
            line[12] == ' ' && !ss.fail() && ss.eof());
}
bool checkDate(const string &line)
{
    int year = std::atoi(line.substr(0, 4).c_str());
    int month = std::atoi(line.substr(5, 2).c_str());
    int day = std::atoi(line.substr(8, 2).c_str());
    return year < 2009 || month > 12 || day > 31;
}
void BitcoinExchange::readDataFromFile(const std::string &file)
{
    long double num;
    long double value;

    std::ifstream file_name(file, std::ios::in);
    std::string line;
    while (getline(file_name, line))
        parsedData.push_back(line);
    file_name.close();
    std::vector<std::string>::iterator it = parsedData.begin();
    int i = 0;
    for (; it != (parsedData.end() - 1); it++)
    {
        if (!isValidDateLine(*(it + 1)) ||
            !validateMonths(*(it + 1)) ||
            checkDate(*(it + 1)))
        {
            std::cout
                << "Error: bad input => " << *(it + 1) << "\n";
            continue;
        }
        else
        {

            std::string value = *(it + 1);
            value = value.substr(VALUE);
            std::stringstream ss(value);
            ss >> num;
            if (num < 0)
            {
                std::cout
                    << "Error: not a positive number." << "\n";
                continue;
            }
            else if (num > 1000)
            {

                std::cout
                    << "Error: too large a number." << "\n";
                continue;
            }
        }

        dateValueMapIn.clear();
        string key = *(it + 1);
        dateValueMapIn[key.substr(0, DATE)] = num;
        std::map<std::string, double>::iterator it = dateValueMapIn.begin();
        std::map<std::string, double>::iterator targetDate = dateValueMap.lower_bound(it->first);

        if (it->first.compare(targetDate->first))
        {
            if (targetDate != dateValueMap.begin())
            {
                --targetDate;
                std::cout << targetDate->first << " => "
                          << targetDate->second << " = "
                          << targetDate->second * it->second << "\n";
            }
        }
        else
            std::cout << targetDate->first << " => "
                      << targetDate->second << " = "
                      << targetDate->second * it->second << "\n";
    }
}

bool IsValidCsv(const string &buffer)
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

void BitcoinExchange::setMap(const string &av)
{
    std::ifstream file_name("data.csv");
    std::ifstream input_file(av);
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