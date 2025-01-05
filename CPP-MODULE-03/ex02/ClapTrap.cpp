/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:05:53 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 13:05:54 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name) : _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Parametrized constructor of ClapTrap called" << std::endl;
};

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor of ClapTrap called" << std::endl;
};

ClapTrap &ClapTrap::operator=(const ClapTrap &obj)
{
    if (this != &obj)
    {
        this->_name = obj._name;
        this->_attackDamage = obj._attackDamage;
        this->_energyPoints = obj._energyPoints;
        this->_hitPoints = obj._hitPoints;
    }
    return (*this);
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
    *this = obj;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor of ClapTrap called" << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        std::cout << "ClapTrap " << _name << " attacks " << target
                  << ", causing " << _attackDamage << " points of damage!" << std::endl;
        --_energyPoints;
    }
    else
        std::cout << "ClapTrap " << _name << " cannot attack because it has no energy or hit points left!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints > 0 && _energyPoints > 0)
    {
        if (_hitPoints < amount)
            _hitPoints = 0;
        else
            _hitPoints -= amount;
        std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " has no hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints > 0 && _hitPoints > 0)
    {
        _energyPoints--;
        _hitPoints += amount;
        std::cout << "ClapTrap " << _name << " repairs itself for " << amount << " hit points!" << std::endl;
    }
    else
        std::cout << "ClapTrap " << _name << " has no energy left to repair!" << std::endl;
}
