/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:41:15 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 16:41:16 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "FragTrap.hpp"

int main()
{
    FragTrap trap1("Trap1");

    FragTrap trap2("Trap2");

    trap1.attack("Trap2");
    trap1.takeDamage(54);
    trap1.beRepaired(15);

    trap2.attack("trap1");
    trap2.takeDamage(11);

    trap2.beRepaired(5);
    trap1.highFivesGuys();
}