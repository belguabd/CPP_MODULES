/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:38:20 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/03 10:34:13 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>

class Array
{
private:
    T       *data;
    size_t length;

public:
    Array();
    Array(unsigned int n);
    Array(const Array<T> &other);
    Array<T> &operator=(const Array<T> &other); 
    ~Array();

    size_t size() const;

    T &operator[](size_t index);
    const T &operator[](size_t index) const;
};

template <class T> 
Array<T>::Array() : data(NULL), length(0) {}

template <class T>
Array<T>::Array(unsigned int n) : length(n)
{
    data = new T[length];
    length = n;
}

template <class T>
Array<T>::Array(const Array<T> &other) : length(other.length)
{
    data = new T[length];
    for (size_t i = 0; i < length; i++)
    {
        data[i] = other.data[i];
    }
}

template <class T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        delete[] data;
        data = new T[other.length];
        for (size_t i = 0; i < length; i++)
        {
            data[i] = other.data[i];
        }
    }
    return (*this);
}

template <class T>
size_t Array<T>::size() const { return this->length; }

template <class T>
T &Array<T>::operator[](size_t index)
{
    if (index >= length)
        throw(std::out_of_range("Index out of range"));
    return data[index];
}

template <class T>
const T &Array<T>::operator[](size_t index) const
{
    if (index >= length)
        throw(std::out_of_range("Index out of range"));
    return data[index];
}

template <class T>
Array<T>::~Array() { delete[] data; }

#endif