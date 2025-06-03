#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#define LENGTH 13
#define VALUE 13
#define DATE 10


class BitcoinExchange
{
    private:
    long double                         num;
    std::map<std::string, double>        dateValueMap;
    
    
    public:
    void                                main(int argc, char **argv);
        void                                parseInput(const std::string &filename);
        void                                parseLine(const std::string &line);
        void                                setMap(const std::string &av);
        
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        ~BitcoinExchange();
    };


#endif // PMERGEME_HPP

