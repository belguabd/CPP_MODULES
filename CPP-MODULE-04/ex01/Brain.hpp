/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 19:57:38 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/05 17:16:48 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(const Brain &other);
        Brain &operator=(const Brain &other);
        ~Brain();
};

#endif