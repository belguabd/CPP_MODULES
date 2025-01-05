/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:05 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 17:18:00 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    this->brain = new Brain();
    std::cout << "Default constructor called" << std::endl;
};

Cat &Cat::operator=(const Cat &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain(*other.brain);
    return (*this);
}

Cat::Cat(const Cat &other)
{
    *this = other;
}
void Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
};

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Destructor of Cat called" << std::endl;
}