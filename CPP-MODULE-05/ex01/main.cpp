/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:29:03 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/26 16:13:35 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{

    try
    {
        Bureaucrat Az("Aziz Akhannouch", 5);
        Bureaucrat Ab("Abdelilah Benkirane", 17);

        Form contract("Contract", 12, 11);
        contract.beSigned(Az);
        Az.signForm(contract);
        Ab.signForm(contract);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}