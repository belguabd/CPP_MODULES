/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:28:59 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 11:20:29 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) { *this = other; }
Intern &Intern::operator=(const Intern &other)
{
    if (this == &other)
        return *this;
    return *this;
}
Intern::~Intern() {}

AForm *Intern::makeForm(std::string name, std::string target)
{

    std::string names[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    int i = (((names[0] == name) * 0) + ((names[1] == name) * 1) + ((names[2] == name) * 2));

    switch (i)
    {
    case 0:
        std::cout << "Intern creates PresidentialPardonForm" << std::endl;
        return new PresidentialPardonForm(target);
    case 1:
        std::cout << "Intern creates RobotomyRequestForm" << std::endl;
        return new RobotomyRequestForm(target);
    case 2:
        std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
        return new ShrubberyCreationForm(target);
    default:
        std::cout << "Error: this form doesn't exist" << std::endl;
    }
    return (NULL);
}