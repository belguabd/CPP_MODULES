/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:36 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 14:22:08 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
    std::string type;

public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    Animal(std::string type);
    virtual void makeSound() const;
    std::string getType() const;
    virtual ~Animal();
};

#endif