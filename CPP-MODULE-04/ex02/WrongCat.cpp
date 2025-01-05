/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 18:01:35 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 12:52:51 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "Default constructor called" << std::endl;
};

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

WrongCat::WrongCat(const WrongCat &other)
{
    this->type = other.type;
}

void WrongCat::makeSound() const
{
    std::cout << "Meow" << std::endl;
};

WrongCat::~WrongCat()
{
    std::cout << "Destructor of WrongCat called" << std::endl;
}