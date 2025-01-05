/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:51:53 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 13:17:37 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 137, 145), target("default") {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    target = other.target;
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {};

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target)
    : AForm("ShrubberyCreationForm", 137, 145), target(target) {};

void ShrubberyCreationForm::execute(const Bureaucrat &other) const
{

    if (!getSign())
        throw(AForm::GradeTooLowException());
    if (other.getGrade() > getExecuteGrade())
        throw(AForm::GradeTooLowException());

    std::ofstream file(target + "_shrubbery");
    if (file.is_open())
    {
        std::string tree;
        tree += "          &&& &&  & &&\n";
        tree += "      && &\\/&\\|& ()|/ @, &&\n";
        tree += "      &\\/(/&/&||/& /_/)_&/_&\n";
        tree += "   &() &\\/&|()|/&\\/ '%\" & ()\n";
        tree += "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n";
        tree += "&&   && & &| &| /& & % ()& /&&\n";
        tree += " ()&_---()&\\\\&\\|&&-&&--%---()~\n";
        tree += "     &&     \\\\||| \n";
        tree += "             |||\n";
        tree += "             |||\n";
        tree += "             |||\n";
        tree += "             |||\n";
        tree += "       , -=-~  .-^- _\n";
        file << tree;
        file.close();
    }
    else
        std::cout << "Error: can't open the file" << std::endl;
}