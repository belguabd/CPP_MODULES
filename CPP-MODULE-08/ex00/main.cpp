/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:30:36 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/03 14:53:50 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Easyfind.hpp"

#include <vector>

int main()
{
    try
    {
        std::vector<int> arr;
        int toFind = 13;
        arr.push_back(12);
        arr.push_back(11);
        arr.push_back(13);
        std::cout << "Found: " << *easyfind(arr, toFind) << std::endl;
        toFind = 14;
        std::cout << "Found: " << *easyfind(arr, toFind) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}