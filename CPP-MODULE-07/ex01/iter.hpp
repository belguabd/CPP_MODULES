/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:20:33 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/03 10:13:48 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T, typename E>
void iter(T *arr, size_t size, E fun)
{
    for (size_t i = 0; i < size; i++)
        fun(arr[i]);
}
