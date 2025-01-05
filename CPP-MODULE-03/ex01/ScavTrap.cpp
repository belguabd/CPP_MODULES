/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:40:29 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/02 14:31:19 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap " << _name << " created" << std::endl;
};

ScavTrap::ScavTrap(const ScavTrap &obj)
{
    this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
    std::cout << "ScavTrap " << this->_name << " copied" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Destructor of ScavTrap called" << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &obj)
{
    if (this == &obj)
        return (*this);
    this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
    std::cout << "ScavTrap " << this->_name << " assigned" << std::endl;
    return (*this);
}
ScavTrap::ScavTrap()
{
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap default constructed" << std::endl;
};

void ScavTrap::attack(const std::string &target)
{
if (_energyPoints > 0)
    {
        std::cout << "ScavTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        --_energyPoints;
    }
    else
        std::cout << "ScavTrap " << _name << " cannot attack because it has no energy or hit points left!" << std::endl;
}
void ScavTrap::guardGate()
{
    if (_hitPoints > 0 )
        std::cout << _name << " is now in Gate keeper mode" << std::endl;
}