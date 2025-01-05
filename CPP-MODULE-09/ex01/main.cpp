/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:28:46 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/24 14:55:52 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <vector>
using namespace std;

int main(int ac, const char *av[])
{

    if (ac != 2)
        return (std::cerr << "Error"
                          << std::endl,
                1);
    RPN rpn(av[1]);
}
