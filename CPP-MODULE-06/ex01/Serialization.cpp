/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:34:34 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/29 13:39:13 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{
}
Serialization::Serialization(const Serialization &other)
{
    *this = other;
}
Serialization &Serialization::operator=(const Serialization &other)
{
    if (this != &other)
        *this = other;
    return *this;
}
Serialization::~Serialization()
{
}

uintptr_t Serialization::serialize(Data *ptr)
{
    uintptr_t num = reinterpret_cast<uintptr_t>(ptr);
    return (num);
}

Data *Serialization::deserialize(uintptr_t raw)
{
    Data *data = reinterpret_cast<Data *>(raw);
    return (data);
}