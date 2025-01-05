/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:36:41 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 15:23:11 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void f()
{
    system("leaks Brain");
}

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "\n";
    j->makeSound();
    i->makeSound();
    std::cout << "\n";

    delete j; // should not create a leak
    delete i;
    return 0;
}
