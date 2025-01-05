/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:46:16 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/30 10:07:03 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
    Data *data = new Data();
    data->age = 16;

    uintptr_t num = Serialization::serialize(data);
    Data *rt_data = Serialization::deserialize(num);

    if (data == rt_data)
        std::cout << "the same address 😄" << rt_data->age << std::endl;
    else
        std::cout << "the address are not the same 😠" << std::endl;
    delete data;
    return 0;
}