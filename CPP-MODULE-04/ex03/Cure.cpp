/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:09:04 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/07 15:40:31 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other)
{
    this->type = other.type;
}
Cure &Cure::operator=(const Cure &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return *this;
}
Cure::~Cure() {}

std::string const &Cure::getType() const
{
    return (this->type);
}

AMateria *Cure::clone() const
{
    Cure *m_pInstance = new Cure(*this);
    return (m_pInstance);
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}