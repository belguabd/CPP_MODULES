/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:41:56 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/02 14:33:13 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap diamondTrap1("Trap1");
    DiamondTrap diamondTrap2("Trap2");
    diamondTrap1.attack("Trap2");
    diamondTrap1.takeDamage(10);

    diamondTrap1.beRepaired(2);
    diamondTrap1.guardGate();
    diamondTrap1.highFivesGuys();
    diamondTrap1.whoAmI();
    return (0);
}