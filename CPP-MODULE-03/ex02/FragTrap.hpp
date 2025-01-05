/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:41:10 by belguabd          #+#    #+#             */
/*   Updated: 2024/09/23 16:41:11 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    FragTrap(const FragTrap &obj);
    FragTrap &operator=(const FragTrap &obj);
    ~FragTrap();

    FragTrap(std::string name);
    void highFivesGuys(void);
};
#endif