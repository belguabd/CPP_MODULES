/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:38:19 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 12:51:58 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*start Orthodox Canonical Form*/

Bureaucrat::Bureaucrat() : name("default"), grade(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name)
{
    this->grade = other.grade;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return (*this);
    this->grade = other.grade;

    return *this;
}
Bureaucrat::~Bureaucrat() {};

/*end Orthodox Canonical Form*/

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw(GradeTooHighException());
    else if (grade > 150)
        throw(GradeTooLowException());
    this->grade = grade;
}

std::string Bureaucrat::getName() const { return (this->name); }
int Bureaucrat::getGrade() const { return (this->grade); }

void Bureaucrat::incrementGrade()
{
    if (grade <= 1)
        throw(GradeTooHighException());
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade >= 150)
        throw(GradeTooLowException());
    grade++;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &obj)
{
    out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}