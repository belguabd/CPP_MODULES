/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:18:23 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/26 16:41:22 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
public:
    /*start Orthodox Canonical Form*/
    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    ~AForm();
    /*end Orthodox Canonical AForm*/

    AForm(std::string name, int executeGrade, int signGrade);

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
    virtual void execute(Bureaucrat const &executor) const = 0;

private:
    const std::string name;
    const int executeGrade;
    const int signGrade;
    bool is_sign;
};

std::ostream &operator<<(std::ostream &out, const AForm &obj);
#endif