/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:26:26 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 17:21:44 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    private:
        Brain *brain;

    public:
        Dog();
        Dog(const Dog &other);
        Dog &operator=(const Dog &other);
        void makeSound() const;
        ~Dog();
};

#endif