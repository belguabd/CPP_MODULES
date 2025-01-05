/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:24:50 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/03 09:10:05 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T &x)
{
    std::cout << x << std::endl;
};

template <typename T>
void increment(T &x) { ++x; }

int main()
{
  int arr_i[] = {1, 2, 3, 4};
  size_t size_i = sizeof(arr_i) / sizeof(int);
  std::cout << "int array:" << std::endl;
  ::iter(arr_i, size_i, ::print<int>);
  std::cout << "incremented int array:" << std::endl;
  ::iter(arr_i, size_i, ::increment<int>);
  ::iter(arr_i, size_i, ::print<int>);

  std::string arr_s[] = {"1337", "42", "ofppt"};
  std::cout << "string array:" << std::endl;
  ::iter(arr_s, 3, ::print<std::string>);
}