/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:18 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/26 17:26:19 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog(const Dog &other)
{
    this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Destructor of dog called" << std::endl;
}

Dog::Dog() : Animal("Dog")
{
    std::cout << "Default constructor of dog called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}