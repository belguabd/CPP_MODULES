/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:22:10 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/30 10:01:25 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <iostream>
#include <cstdint>

struct Data
{
    int age;
};

class Serialization
{
private:
    Serialization();
    Serialization(const Serialization &other);
    Serialization &operator=(const Serialization &other);
    ~Serialization();
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif