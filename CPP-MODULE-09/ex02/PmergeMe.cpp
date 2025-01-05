/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:22:39 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/25 19:27:39 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int PmergeMe::struggle = -1;

int _Atoi(const std::string &input)
{
    size_t res = 0;
    for (size_t i = 0; i < input.size(); i++)
    {
        res = input[i] - '0' + (10 * res);
        if (res > INT_MAX)
            throw std::invalid_argument("Invalid argument!!");
    }
    return (res);
}

void PmergeMe::parseInput(const std::string &data)
{

    for (size_t i = 0; i < data.size(); i++)
    {
        if (!std::isdigit(data[i]))
            throw std::invalid_argument("Invalid argument!!");
    }
    inputData.push_back(_Atoi(data));
}

void PmergeMe::setData()
{
    std::vector<int>::iterator it = inputData.begin();

    for (; it != inputData.end();)
    {
        if ((it + 1) == inputData.end())
            break;
        std::pair<int, int> pr = std::make_pair(*it, *(it + 1));
        data.push_back(pr);
        it += 2;
    }
    struggle = inputData.size() % 2 != 0 ? *(inputData.end() - 1) : -1;
}
void PmergeMe::getGreaterElement()
{
    std::vector<std::pair<int, int> >::iterator it = data.begin();
    for (; it != data.end(); it++)
    {
        size_t tmp = it->first;
        if (it->first < it->second)
            it->first = it->second, it->second = tmp;
    }
}
void PmergeMe::sortAscending()
{
    std::vector<std::pair<int, int> >::iterator it = data.begin() + 1;
    for (; it != data.end(); it++)
    {

        size_t current = it->first;
        std::vector<std::pair<int, int>
 >::iterator j = (it - 1);

        while (j >= data.begin() && j->first > current)
        {
            (j + 1)->first = j->first;
            j--;
        }
        (j + 1)->first = current;
    }
}
void PmergeMe::binarySearch()
{

    std::vector<std::pair<int, int> >::iterator it = data.begin();
    for (; it != data.end(); it++)
        mainChian.push_back(it->first);
    it = data.begin();
    for (; it != data.end(); it++)
        pend.push_back(it->second);

    std::vector<int>::iterator iter = pend.begin();
    for (; iter != pend.end(); iter++)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChian.begin(), mainChian.end(), *iter);
        mainChian.insert(pos, *iter);
    }
    iter = mainChian.begin();
    for (; iter != mainChian.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
}
void PmergeMe::main()
{
    setData();
    getGreaterElement();
    sortAscending();
    binarySearch();
}