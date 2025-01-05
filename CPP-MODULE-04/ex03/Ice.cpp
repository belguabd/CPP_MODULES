/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:03:54 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 16:18:45 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other)
{
    this->type = other.type;
}
Ice &Ice::operator=(const Ice &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return *this;
}
Ice::~Ice() {}


std::string const &Ice::getType() const
{
    return (this->type);
}

AMateria *Ice::clone() const
{
    Ice *m_pInstance = new Ice(*this);
    return (m_pInstance);
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
