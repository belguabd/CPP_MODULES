/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:58:22 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 10:28:18 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{

    try
    {
        Bureaucrat Az("Aziz Akhannouch", 1);
        std::string target = "HOME";
        RobotomyRequestForm P(target);
        ShrubberyCreationForm S(target);
        PresidentialPardonForm R(target);
        
        std::cout << Az << std::endl;
        std::cout << P << std::endl;
        std::cout << S << std::endl;
        std::cout << R << std::endl;
        std::cout << "-----------------------------------" << std::endl;
        Az.signForm(P);
        Az.executeForm(P);
        Az.signForm(S);
        Az.executeForm(S);
        Az.signForm(R);
        Az.executeForm(R);
        std::cout << "-----------------------------------" << std::endl;
        
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}