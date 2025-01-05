/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:38:28 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/26 19:05:27 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"
class AForm;
 
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
    int getGrade() const;
    void signForm(AForm &other);
    void executeForm(AForm const & form);

private:
    const std::string name;
    int grade;
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &obj);

#endif