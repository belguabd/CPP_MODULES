/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:05 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/28 12:26:29 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Default constructor called" << std::endl;
};

Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

Cat::Cat(const Cat &other)
{
    this->type = other.type;
}
void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
};

Cat::~Cat()
{
    std::cout << "Destructor of Cat called" << std::endl;
}