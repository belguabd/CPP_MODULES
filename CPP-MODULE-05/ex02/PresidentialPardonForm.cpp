/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:23:38 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 09:49:16 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*start Orthodox Canonical Form*/
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other),
                                                                                      target(other.target) {}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    if (this == &other)
        return *this;
    AForm::operator=(other);
    target = other.target;
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
/*start Orthodox Canonical Form*/

PresidentialPardonForm::PresidentialPardonForm(std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target(target)
{
}
void PresidentialPardonForm::execute(const Bureaucrat &other) const
{
    if (!getSign())
        throw(GradeTooLowException());
    if (other.getGrade() > getExecuteGrade())
        throw(GradeTooLowException());
    std::cout << "Informs that " << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};