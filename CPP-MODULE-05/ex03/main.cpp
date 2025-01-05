/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:58:22 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 11:46:42 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main()
{

    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    Bureaucrat Az("Aziz Akhannouch", 1);
    std::cout << Az << std::endl;
    Az.signForm(*rrf);
    Az.executeForm(*rrf);
    delete rrf;
}