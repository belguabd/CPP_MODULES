/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:40:22 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 16:40:23 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "ScavTrap.hpp"

int main()
{
    ScavTrap Scav1("Scav1");
    ScavTrap Scav2("Scav2");

    Scav1.attack("Scav2");
    Scav1.takeDamage(20);

    Scav2.attack("Scav1");
    Scav1.guardGate();

    Scav1.beRepaired(10);
    Scav1.takeDamage(10);
}