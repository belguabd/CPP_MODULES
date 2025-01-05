/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:46:44 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/07 16:22:21 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria &AMateria::operator=(const AMateria &other)
{
    if (this == &other)
        return (*this);
    this->type = other.type;
    return (*this);
}

AMateria::AMateria() : type("unknown") {}

AMateria::AMateria(const AMateria &other) { this->type = other.type; }

AMateria::AMateria(std::string const &type) : type(type) {}

std::string const &AMateria::getType() const { return this->type; }

void AMateria::use(ICharacter &target)
{
    (void)target;
}

AMateria::~AMateria() {};   