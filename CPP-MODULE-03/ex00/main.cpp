/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:06:20 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 13:06:21 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ClapTrap.hpp"

int main()
{
    ClapTrap Trap1("Trap1");
    ClapTrap Trap2("Trap2");

    Trap1.attack("Trap2");
    Trap2.takeDamage(30);

    Trap2.attack("Trap1");
    Trap1.takeDamage(30);
    return 0;
}
