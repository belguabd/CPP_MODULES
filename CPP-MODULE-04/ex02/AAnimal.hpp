/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:36 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 17:23:27 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal 
{
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);
    
    AAnimal(std::string type);
    virtual void makeSound() const = 0;
    std::string getType() const;
    virtual ~AAnimal();
};

#endif