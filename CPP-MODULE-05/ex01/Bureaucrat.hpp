/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:38:28 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/26 15:51:58 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"
class Form;
 
class  Bureaucrat
{
public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    Bureaucrat(std::string name, int grade);

    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    void incrementGrade();
    void decrementGrade();

    std::string getName();
    int getGrade();
    void signForm(Form &other);

private:
    const std::string name;
    int grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);

#endif