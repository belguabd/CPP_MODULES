/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:42 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 16:08:18 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Undefined")
{
    std::cout << "Default constructor of Animal called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    puts("animal");
    if (this != &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

AAnimal::AAnimal(const AAnimal &other)
{
    this->type = other.type;
}

AAnimal::~AAnimal()
{
    std::cout << "Destructor of animal is called" << std::endl;
}

AAnimal::AAnimal(std::string name) : type(name)
{
    std::cout << "Animal constructor with parameters has been called" << std::endl;
}

void AAnimal::makeSound() const
{
    std::cout << "This is a new message" << std::endl;
}

std::string AAnimal::getType() const
{
    return (this->type);
}