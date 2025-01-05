/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:10:38 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/25 16:22:48 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, const char *av[])
{
    if (ac == 1)
        return (std::cerr << "The number of arguments is not enough!!", 1);
    PmergeMe Pm;

    size_t i = 1;
    try
    {
        for (; av[i]; i++)
            Pm.parseInput(av[i]);
        Pm.main();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
