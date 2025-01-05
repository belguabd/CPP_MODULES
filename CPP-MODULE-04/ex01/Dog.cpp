/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:18 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 15:27:09 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    
    this->brain = new Brain();
    std::cout << "Default constructor of dog called" << std::endl;
}
Dog::Dog(const Dog &other)
{
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    if (this != &other)
        return (*this);
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain(*other.brain);
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Woof Woof" << std::endl;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Destructor of dog called" << std::endl;
}