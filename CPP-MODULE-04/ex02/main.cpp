/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:29:01 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 16:11:12 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

void f()
{
    system("leaks Brain");
}

int main()
{
    const AAnimal *j = new Dog();
    const AAnimal *i = new Cat();
    j->makeSound();
    i->makeSound();
    delete j; // should not create a leak
    delete i;
    return 0;
}
