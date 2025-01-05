/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:47:36 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/04 14:35:00 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>

class Span
{
private:
    std::vector<int> _numbers;
    size_t _size;

public:
    Span();
    Span(const Span &src);
    Span &operator=(const Span &src);
    ~Span();

    Span(unsigned int N);
    void addNumber(unsigned int num);
    unsigned int shortestSpan();
    unsigned int longestSpan();
    template <typename iterator>
    void addRange(iterator begin, iterator end);
};

template <typename iterator>
void Span::addRange(iterator start, iterator end)
{
    unsigned int range = std::distance(start, end);
    if ((_numbers.size() + range) > _size)
        throw std::length_error("The span is full");
    _numbers.insert(_numbers.end(), start, end);
}