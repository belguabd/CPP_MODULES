/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 10:35:07 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 15:51:27 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

std::string const &Character::getName() const { return (this->name); }

void Character::equip(AMateria *m)
{
    int i;

    if (!m)
        return;
    i = 0;
    while (i < 4)
    {
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return;
        }
        i++;
    }
    delete m;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4)
        _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx < 0 || idx > 4 || !_inventory[idx])
        return;
    _inventory[idx]->use(target);
}

Character::Character() : name("unknown") {}


Character::Character(std::string name) : name(name), _inventory() {}

Character::Character(const Character &other) : name(other.name)
{
    int i;
    i = 0;

    while (i < 4)
    {
        if (other._inventory[i])
            this->_inventory[i] = other._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}
Character &Character::operator=(const Character &other)
{
    int i;

    i = 0;
    if (this != &other)
    {
        this->name = other.name;
        while (i < 4)
        {
            delete _inventory[i];
            _inventory[i] = NULL;
            i++;
        }
        i = 0;
        while (i < 4)
        {
            if (other._inventory[i])
                _inventory[i] = other._inventory[i]->clone();
            else
                _inventory[i] = NULL;
            i++;
        }
    }
    return (*this);
}
Character::~Character()
{
    for (size_t i = 0; i < 4; i++)
    {
        if (_inventory[i])
            delete _inventory[i];
    }
};