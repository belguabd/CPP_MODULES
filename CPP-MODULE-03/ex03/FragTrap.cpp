/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:41:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 18:32:42 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap " << _name << " constructed" << std::endl;
};

void FragTrap::highFivesGuys()
{
    if (_hitPoints > 0 )
        std::cout << "Hey there! High five! ✋ Let's celebrate!" << std::endl;
}

FragTrap::FragTrap()
{
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "FragTrap default constructed" << std::endl;
};

FragTrap::FragTrap(const FragTrap &obj)
{
    this->_name = obj._name;
    this->_hitPoints = obj._hitPoints;
    this->_energyPoints = obj._energyPoints;
    this->_attackDamage = obj._attackDamage;
    std::cout << "FragTrap " << this->_name << " copied" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &obj)
{
    if (this == &obj)
        return (*this);
    _name = obj._name;
    _hitPoints = obj._hitPoints;
    _energyPoints = obj._energyPoints;
    _attackDamage = obj._attackDamage;
    std::cout << "FragTrap " << _name << " assigned" << std::endl;
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " destroyed." << std::endl;
}
