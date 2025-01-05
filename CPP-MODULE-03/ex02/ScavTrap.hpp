/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:41:26 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 16:41:27 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();
    ScavTrap(const ScavTrap &obj);
    ScavTrap &operator=(const ScavTrap &obj);
    ~ScavTrap();

    ScavTrap(std::string name);
    void attack(const std::string &target);
    void guardGate();
};
#endif