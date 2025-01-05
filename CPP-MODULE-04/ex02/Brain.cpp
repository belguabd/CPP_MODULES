/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:57:42 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 12:53:54 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Default constructor called " << std::endl;
}
Brain::Brain(const Brain &other)
{
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
    if (this == &other)
        return (*this);
    for (size_t i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Destructor of Brain called" << std::endl;
}