/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:00:09 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 16:04:17 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include <iostream>
#include "ICharacter.hpp"

class Ice : public AMateria
{

public:
    Ice();
    Ice &operator=(const Ice &other);
    Ice(const Ice &other);
    ~Ice();

    std::string const &getType() const;
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif