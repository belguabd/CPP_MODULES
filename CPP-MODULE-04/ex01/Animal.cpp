/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:42 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 16:08:08 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Undefined")
{
    std::cout << "Default constructor of Animal called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
    puts("animal");
    if (this != &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

Animal::Animal(const Animal &other)
{
    this->type = other.type;
}

Animal::~Animal()
{
    std::cout << "Destructor of animal is called" << std::endl;
}

Animal::Animal(std::string name) : type(name)
{
    std::cout << "Animal constructor with parameters has been called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "This is a new message" << std::endl;
}

std::string Animal::getType() const
{
    return (this->type);
}