/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 19:36:41 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/08 16:11:55 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

void f()
{
    system("leaks Animal");
}
int main()
{
    // atexit(f);
    {
        Animal *dog = new Dog();
        dog->makeSound(); // Output the sound of a dog
        std::cout << dog->getType() << " " << std::endl;
        delete dog;
    }
    std::cout << "\n";
    {
        Animal *cat = new Cat();
        cat->makeSound(); // Output the sound of a cat
        std::cout << cat->getType() << " " << std::endl;
        delete cat;
    }
    std::cout << "\n";
    {
        Animal *animal = new Animal();
        animal->makeSound(); // Output the sound of a animal
        std::cout << animal->getType() << " " << std::endl;
        delete animal;
    }
    std::cout << "\n";
    {
        WrongAnimal *animal = new WrongCat();
        animal->makeSound(); //Output the sound of a WrongAnimal
        delete animal;
    }
    std::cout << "\n";
    return 0;
}
