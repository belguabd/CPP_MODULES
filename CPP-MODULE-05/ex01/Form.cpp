/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:39:59 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 09:18:33 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*start Orthodox Canonical Form*/

Form::Form() : name("Default Form"), executeGrade(1), signGrade(1), is_sign(false) {};

Form::Form(const Form &other) : name(other.name),
                                executeGrade(other.executeGrade),
                                signGrade(other.signGrade),
                                is_sign(other.is_sign) {}

Form &Form::operator=(const Form &other)
{
    if (this == &other)
        return (*this);
    is_sign = other.is_sign;
    return (*this);
}

Form::~Form() {};

/*end Orthodox Canonical Form*/

Form::Form(std::string name, int executeGrade, int signGrade)
    : name(name), executeGrade(executeGrade), signGrade(signGrade), is_sign(false)
{
    if (executeGrade < 1 || signGrade < 1)
        throw(GradeTooHighException());
    else if (executeGrade > 150 || signGrade > 150)
        throw(GradeTooLowException());
};

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

std::string Form::getName() const { return this->name; }

int Form::getExecuteGrade() const { return this->executeGrade; }

int Form::getSignGrade() const { return this->signGrade; }

bool Form::getSign() const { return this->is_sign; }

void Form::beSigned(Bureaucrat &other)
{
    if (other.getGrade() > signGrade)
        throw(GradeTooLowException());
    this->is_sign = true;
}

std::ostream &operator<<(std::ostream &out, const Form &obj)
{
    out << "Name: " << obj.getName()
        << ", Execute grade: " << obj.getExecuteGrade()
        << ", Sign grade: " << obj.getSignGrade()
        << ", Is signed: " << (obj.getSignGrade() ? "Yes" : "No");
    return out;
}
