/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:52:35 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/04 14:15:01 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span() : N(0) {};
Span::Span(const Span &src) : _numbers(src._numbers), N(src.N) {};
Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        _numbers = src._numbers;
        N = src.N;
    }
    return *this;
};
Span::~Span() {};

/*
** --------------------------------- METHODS ----------------------------------
*/

Span::Span(unsigned int N) : N(N) {};

void Span::addNumber(int num)
{

    if (_numbers.size() >= N)
        throw std::length_error("The span is full");
    _numbers.push_back(num);
};

int Span::shortestSpan()
{

    if (N < 2)
        throw std::length_error("The container must have at least two elements.");
    std::sort(_numbers.begin(), _numbers.end());

    std::vector<int>::iterator it = _numbers.begin();
    int shortest = *(it + 1) - *it;
    it++;
    for (; it != _numbers.end() - 1; ++it)
    {
        if (shortest > (*(it + 1) - (*it)))
            shortest = (*(it + 1) - (*it));
    }
    return (shortest);
}

int Span::longestSpan()
{

    if (_numbers.size() < 2)
        throw std::length_error("The container must have at least two elements.");
    std::sort(_numbers.begin(), _numbers.end());
    int longest = _numbers.back() - _numbers.front();
    return (longest);
}

void Span::addNumbersIndividually()
{
    for (size_t i = 0; i < 10000; i++)
        addNumber(i + 5);
}
