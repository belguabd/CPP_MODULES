/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:20:11 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/24 14:56:51 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
class RPN
{
public:
    RPN(const std::string &data);
    
private:
    void RPNCalculator(const std::string &data);
    void parseInput(const std::string &data);
    bool IsOperator(char ch);
    std::list<std::string> list;
    std::stack<double> st;
};