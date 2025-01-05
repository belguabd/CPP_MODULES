/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:14:10 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/30 10:00:41 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{

    if (argc != 2)
        return std::cout << "Invalid argument!!\n", 1;
    std::string data = argv[1];
    ScalarConverter::convert(data);
    return 0;
}