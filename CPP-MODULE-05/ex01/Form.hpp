/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:18:23 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/26 14:10:26 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
    /*start Orthodox Canonical Form*/
    Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();
    /*end Orthodox Canonical Form*/
    
    Form(std::string name, int executeGrade, int signGrade);

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

    std::string getName() const;
    int getExecuteGrade() const;
    int getSignGrade() const;
    bool getSign() const;

    void beSigned(Bureaucrat &other);

private:
    const std::string name;
    const int executeGrade;
    const int signGrade;
    bool is_sign;
};

std::ostream &operator<<(std::ostream &out, const Form &obj);
#endif