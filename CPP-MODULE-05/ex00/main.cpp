/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:44:29 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/27 12:52:12 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat Az("Aziz Akhannouch", 1);
        Bureaucrat Ab("Abdelilah Benkirane", 150);
        std::cout << Az << "\n";
        std::cout << Ab << "\n";
        Ab.decrementGrade();
        Az.incrementGrade();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}
