/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:49:27 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/17 10:57:29 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP
#include <iostream>
#include "Base.hpp"
#include "C.hpp"
#include "A.hpp"
#include "B.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base& p);

#endif