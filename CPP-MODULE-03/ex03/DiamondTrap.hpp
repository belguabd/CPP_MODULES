/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:41:41 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 18:47:38 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
        std::string _name;

    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &obj);
        DiamondTrap &operator=(const DiamondTrap &obj);
        ~DiamondTrap();
        std::string getName(){return _name;}
        
        DiamondTrap(std::string name);
        void attack(const std::string &target);
        void whoAmI();
};
#endif