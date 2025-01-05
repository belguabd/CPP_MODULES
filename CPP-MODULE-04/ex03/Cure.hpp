/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 17:07:49 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 16:01:42 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "ICharacter.hpp"

class Cure : public AMateria
{

public:
    Cure();
    Cure &operator=(const Cure &other);
    Cure(const Cure &other);
    ~Cure();

    std::string const &getType() const;
    AMateria *clone() const;
    void use(ICharacter &target);
};

#endif