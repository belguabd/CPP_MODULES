/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:06:15 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 13:52:54 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef  CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap &operator=(const ClapTrap &obj);
        ClapTrap(const ClapTrap &obj);
        ~ClapTrap();

        
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};


#endif