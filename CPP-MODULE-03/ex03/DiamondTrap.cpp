/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:41:36 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 16:41:37 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;

    std ::cout << "DiamondTrap " << _name << " created" << std::endl;
};

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
};

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap is: " << DiamondTrap::_name
              << " ClapTrap is: " << ScavTrap::_name << std::endl;
};

DiamondTrap::DiamondTrap()
{
    ClapTrap::_name += "_clap_name";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 30;
    std::cout << "DiamondTrap default constructed" << std::endl;
};

DiamondTrap::DiamondTrap(const DiamondTrap &obj)
{
    this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
    std::cout << "DiamondTrap " << this->_name << " copied" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj)
{
    if (this == &obj)
        return (*this);
    this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
    std::cout << "DiamondTrap " << this->_name << " assigned" << std::endl;
    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "Destructor of DiamondTrap called" << std::endl;
}