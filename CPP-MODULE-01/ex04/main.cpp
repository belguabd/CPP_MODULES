#include <iostream>
#include <fstream>

int main(int ac, char *av[])
{
    if (ac != 4)
        std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
    std::fstream fs;
    fs.open(av[1], std::fstream::in | std::fstream::out);
    if (!fs.is_open())
    {
        std::cerr << "Error opening file." << std::endl;
        return (1);
    }
    std::string line;
    std::string stringFound = av[2];
    std::string stringReplace = av[3];
    std::string result;
    while (getline(fs, line))
        result += line + '\n';
    size_t i = 0;
    std::string newResult;
    while (i < result.size())
    {
        if (result.substr(i, stringFound.size()) == stringFound)
        {
            newResult += stringReplace;
            i += stringFound.size();
        }
        else
            newResult += result[i++];
    }
    fs.close();
    fs.open("newFile.txt", std::fstream::out | std::fstream::trunc);
    fs << newResult.substr(0, newResult.size() - 1);
    fs.close();
}
