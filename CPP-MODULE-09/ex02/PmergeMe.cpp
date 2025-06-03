#include "PmergeMe.hpp"

void PmergeMe::parseArgs(char *args[])
{
    int nbr;
    int i;

    i = 1;
    while (args[i])
    {
        std::string arg = args[i];
        std::stringstream ss(arg);
        ss >> nbr;
        if (!ss.eof() || ss.fail() || nbr < 0)
            throw std::runtime_error("Invalid argument");
        numbers.push_back(nbr);
        i++;
    }
}

void PmergeMe::d_parseArgs(char *args[])
{
    int nbr;
    int i;

    i = 1;
    while (args[i])
    {
        std::string arg = args[i];
        std::stringstream ss(arg);
        ss >> nbr;
        if (!ss.eof() || ss.fail() || nbr < 0)
            throw std::runtime_error("Invalid argument");
        d_numbers.push_back(nbr);
        i++;
    }
}

std::vector<long double> getNumbers(int start, int end)
{
    std::vector<long double> numbers;
    while (--end > start)
        numbers.push_back(end);
    return numbers;
}

std::vector<long double> PmergeMe::getJacobsthalNumbers(size_t n)
{
    std::vector<long double> jacobSeq;

    if (n == 0)
        return jacobSeq;
    /* J(n) = J(n-1) + 2*J(n-2)*/
    jacobSeq.push_back(0); // J(0)
    jacobSeq.push_back(1); // J(1)

    for (long double i = 2;; ++i)
    {
        long double next = jacobSeq[i - 1] + 2 * jacobSeq[i - 2];
        if (next >= n)
            break;
        jacobSeq.push_back(next);
    }
    if (jacobSeq.size() > 2)
        jacobSeq.erase(jacobSeq.begin(), jacobSeq.begin() + 2);

    return jacobSeq;
}

void displayVector(std::vector<long double> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "\n");
}

std::vector<int> PmergeMe::mergeInsertion(std::vector<int> &_input)
{
    if (_input.size() <= 1)
        return _input;
    std::vector<std::pair<int, int> > numberPairs;
    std::vector<int> _main;
    std::vector<int> _pend;

    std::vector<int>::iterator it;
    it = _input.begin();
    for (; it != _input.end();)
    {
        if ((it + 1) == _input.end())
            break;
        numberPairs.push_back(std::make_pair(*it, *(it + 1)));
        it += 2;
    }
    this->odd = (_input.size() % 2 != 0) ? _input.back() : -1;
    std::vector<std::pair<int, int> >::iterator it_pair;
    it_pair = numberPairs.begin();
    for (; it_pair != numberPairs.end(); it_pair++)
    {
        _main.push_back(std::max(it_pair->first, it_pair->second));
        _pend.push_back(std::min(it_pair->first, it_pair->second));
    }
    if (this->odd != -1)
        _pend.push_back(this->odd);
    _main = mergeInsertion(_main);
    std::vector<long double> jacobSeq = getJacobsthalNumbers(_pend.size());
    std::vector<long double> indices = jacobSeq;

    if (_pend.size() >= 3)
    {
        for (size_t i = 1; i < jacobSeq.size(); i++)
        {
            std::vector<long double> numbers = getNumbers(jacobSeq[i - 1], jacobSeq[i]);
            if ((size_t)numbers.back() > _pend.size())
                break;
            std::vector<long double>::iterator it = std::upper_bound(indices.begin(), indices.end(), numbers[0]);
            indices.insert(it + 1, numbers.begin(), numbers.end());
        }

        std::vector<long double>::iterator it = std::max_element(indices.begin(), indices.end());
        for (size_t i = *it; i < _pend.size(); i++)
            indices.push_back(i + 1);
    }
    else
    {
        indices.clear();
        if (_pend.size() == 1)
            indices.push_back(1);
        else if (_pend.size() == 2)
        {
            indices.push_back(1);
            indices.push_back(2);
        }
    }
    for (size_t i = 0; i < indices.size(); i++)
    {
        if ((size_t)indices[i] <= _pend.size())
        {
            int value = _pend[indices[i] - 1];
            std::vector<int>::iterator it = std::lower_bound(_main.begin(), _main.end(), value);
            _main.insert(it, value);
        }
    }
    return _main;
}

void printVector(const std::vector<int> &vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "\n");
}
void printDeque(const std::deque<int> &deq)
{
    for (size_t i = 0; i < deq.size(); ++i)
        std::cout << deq[i] << (i + 1 < deq.size() ? " " : "\n");
}

void PmergeMe::main(int argc, char *args[])
{
    if (argc == 1)
    {
        std::cerr << "Usage: ./PmergeMe <list of integers>" << std::endl;
        return;
    }

    try
    {

        clock_t vectorStartTime = clock();
        parseArgs(args);
        std::cout << "Before: ";
        for (size_t i = 0; i < numbers.size(); ++i)
            std::cout << numbers[i] << " ";

        std::cout << "\n";
        std::vector<int> sortedVec = mergeInsertion(numbers);
        clock_t vectorEndTime = clock();
        

        std::cout << "After: ";
        for (size_t i = 0; i < sortedVec.size(); ++i)
            std::cout << sortedVec[i] << " ";
        std::cout << "\n";
        
        double timeVec = static_cast<double>(vectorEndTime - vectorStartTime) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Time to process a range of " << numbers.size()
                  << " elements with std::vector : " << std::setprecision(5)
                  << timeVec << " us" << std::endl;
        clock_t dequeStartTime = clock();
        d_parseArgs(args);
        std::deque<int> sortedDeq = mergeInsertion(d_numbers);
        clock_t dequeEndTime = clock();
        double timeDeq = static_cast<double>(dequeEndTime - dequeStartTime) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Time to process a range of " << d_numbers.size()
                  << " elements with std::deque  : " << std::setprecision(5)
                  << timeDeq << " us" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error" << std::endl;
    }
}

/*----------------------------------
  Begin: Merge-Insertion logic using std::deque
----------------------------------*/

std::deque<long double> d_getNumbers(int start, int end)
{
    std::deque<long double> numbers;
    while (--end > start)
        numbers.push_back(end);
    return numbers;
}

std::deque<long double> PmergeMe::d_getJacobsthalNumbers(size_t n)
{
    std::deque<long double> jacobSeq;

    if (n == 0)
        return jacobSeq;
    /* J(n) = J(n-1) + 2*J(n-2)*/
    jacobSeq.push_back(0); // J(0)
    jacobSeq.push_back(1); // J(1)

    for (long double i = 2;; ++i)
    {
        long double next = jacobSeq[i - 1] + 2 * jacobSeq[i - 2];
        if (next >= n)
            break;
        jacobSeq.push_back(next);
    }
    if (jacobSeq.size() > 2)
        jacobSeq.erase(jacobSeq.begin(), jacobSeq.begin() + 2);

    return jacobSeq;
}
std::deque<int> PmergeMe::mergeInsertion(std::deque<int> &_input)
{
    if (_input.size() <= 1)
        return _input;
    std::deque<std::pair<int, int> > numberPairs;
    std::deque<int> _main;
    std::deque<int> _pend;

    std::deque<int>::iterator it;
    it = _input.begin();
    for (; it != _input.end();)
    {
        if ((it + 1) == _input.end())
            break;
        numberPairs.push_back(std::make_pair(*it, *(it + 1)));
        it += 2;
    }
    this->odd = (_input.size() % 2 != 0) ? _input.back() : -1;
    std::deque<std::pair<int, int> >::iterator it_pair;
    it_pair = numberPairs.begin();
    for (; it_pair != numberPairs.end(); it_pair++)
    {
        _main.push_back(std::max(it_pair->first, it_pair->second));
        _pend.push_back(std::min(it_pair->first, it_pair->second));
    }
    if (this->odd != -1)
        _pend.push_back(this->odd);
    _main = mergeInsertion(_main);
    std::deque<long double> jacobSeq = d_getJacobsthalNumbers(_pend.size());
    std::deque<long double> indices = jacobSeq;

    if (_pend.size() >= 3)
    {
        for (size_t i = 1; i < jacobSeq.size(); i++)
        {
            std::deque<long double> numbers = d_getNumbers(jacobSeq[i - 1], jacobSeq[i]);
            if ((size_t)numbers.back() > _pend.size())
                break;
            std::deque<long double>::iterator it = std::upper_bound(indices.begin(), indices.end(), numbers[0]);
            indices.insert(it + 1, numbers.begin(), numbers.end());
        }

        std::deque<long double>::iterator it = std::max_element(indices.begin(), indices.end());
        for (size_t i = *it; i < _pend.size(); i++)
            indices.push_back(i + 1);
    }
    else
    {
        indices.clear();
        if (_pend.size() == 1)
            indices.push_back(1);
        else if (_pend.size() == 2)
        {
            indices.push_back(1);
            indices.push_back(2);
        }
    }
    for (size_t i = 0; i < indices.size(); i++)
    {
        if ((size_t)indices[i] <= _pend.size())
        {
            int value = _pend[indices[i] - 1];
            std::deque<int>::iterator it = std::lower_bound(_main.begin(), _main.end(), value);
            _main.insert(it, value);
        }
    }
    return _main;
}
