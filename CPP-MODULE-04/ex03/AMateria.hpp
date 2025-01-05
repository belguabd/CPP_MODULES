/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:01:54 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/07 16:18:34 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
    std::string type;

public:
    AMateria();
    AMateria &operator=(const AMateria &other);
    AMateria(const AMateria &other);
    virtual ~AMateria();
    
    AMateria(std::string const &type);

    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif