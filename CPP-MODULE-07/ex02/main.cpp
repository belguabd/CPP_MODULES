/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:22:58 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/03 09:19:19 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

int main()
{
    try
    {

        Array<int> arr_i(2);
        arr_i[0] = 1;
        arr_i[1] = 2;
        std::cout << "int array:" << std::endl;
        for (size_t i = 0; i < arr_i.size(); i++)
            std::cout << arr_i[i] << std::endl;
        Array<int> copy_i(arr_i);
        std::cout << "copy of int array:" << std::endl;
        for (size_t i = 0; i < copy_i.size(); i++)
            std::cout << copy_i[i] << std::endl;
        Array<int> assign_i(2);
        assign_i = arr_i;
        std::cout << "assigned int array:" << std::endl;
        for (size_t i = 0; i < assign_i.size(); i++)
            std::cout << assign_i[i] << std::endl;
        std::cout << "out of bound access:" << std::endl;
        std::cout << arr_i[2] << std::endl;

    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}