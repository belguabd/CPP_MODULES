/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:16:06 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 09:52:47 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 45, 72), target("default") {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    target = other.target;
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {};

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    : AForm("RobotomyRequestForm", 45, 72), target(target) {}

void RobotomyRequestForm::execute(const Bureaucrat &other) const
{
    if (!getSign())
        throw(AForm::GradeTooLowException());
    if (other.getGrade() > getExecuteGrade())
        throw(AForm::GradeTooLowException());

    std::srand(std::time(0));
    int nbr_randome = std::rand() % 2;
    std::cout << (nbr_randome ? target + " has been robotomized successfully\n" : "informs that the robotomy failed\n");
}
