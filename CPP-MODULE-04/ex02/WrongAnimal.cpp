/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:00:34 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 12:52:44 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Undefined")
{
    std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    this->type = other.type;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "Destructor of WrongAnimal is called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string name) : type(name)
{
    std::cout << "WrongAnimal constructor with parameters has been called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "cats don't bark" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
