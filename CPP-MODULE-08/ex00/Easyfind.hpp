/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:13:39 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/04 13:17:53 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class NotFoundException : public std::exception
{
    const char *what() const throw()
    {
        return ("Value not found in the container");
    }
};

template <typename T>
typename T::iterator easyfind(T &arge, int to_find)
{
    typename T::iterator it;
    it = std::find(arge.begin(), arge.end(), to_find);
    if (it != arge.end())
        return it;
    else
        throw NotFoundException();
}
#endif