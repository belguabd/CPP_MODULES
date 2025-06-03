
#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm> 
#include <sys/time.h>
#include <iomanip>
#include <sstream>
#include <limits.h>


class PmergeMe
{
    private:
        std::vector<int>            numbers;
        std::deque<int>             d_numbers;
        int                         odd;

    public:
        void                        main(int argc, char *args[]);
        void                        parseArgs(char *args[]);
        std::vector<int>            mergeInsertion(std::vector<int> &_main);
        std::vector<long double>    getJacobsthalNumbers(size_t n);
        
        void                        d_parseArgs(char *args[]);
        std::deque<int>             mergeInsertion(std::deque<int> &_main);
        std::deque<long double>     d_getJacobsthalNumbers(size_t n);
};

#endif