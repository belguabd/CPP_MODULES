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

Span::Span() : _size(0) {};
Span::Span(const Span &src) : _numbers(src._numbers), _size(src._size) {};
Span &Span::operator=(const Span &src)
{
    if (this != &src)
    {
        _numbers = src._numbers;
        _size = src._size;
    }
    return *this;
};
Span::~Span() {};

/*
** --------------------------------- METHODS ----------------------------------
*/

Span::Span(unsigned int N) : _size(N) {};

void Span::addNumber(unsigned int num)
{

    if (_numbers.size() >= _size)
        throw std::length_error("The span is full");
    _numbers.push_back(num);
};

unsigned int Span::shortestSpan()
{

    if (_size < 2)
        throw std::length_error("The container must have at least two elements.");
    sort(_numbers.begin(), _numbers.end());
    std::vector<int>::iterator it = _numbers.begin();
    unsigned int shortest = *(it + 1) - *it;
    it++;
    for (; it != _numbers.end() - 1; ++it)
    {
        if (shortest > static_cast<unsigned int>(*(it + 1) - (*it)))
            shortest = static_cast<unsigned int>(*(it + 1) - (*it));
    }
    return (shortest);
}

unsigned int Span::longestSpan()
{

    if (_numbers.size() < 2)
        throw std::length_error("The container must have at least two elements.");
    sort(_numbers.begin(), _numbers.end());

    unsigned int longest = _numbers.back() - _numbers.front();

    return (longest);
}

