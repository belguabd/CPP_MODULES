/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:21:55 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/24 15:03:53 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <list>
using namespace std;

bool RPN::IsOperator(char ch)
{
    return (ch != '+' && ch != '-' && ch != '/' && ch != '*');
}

void RPN::parseInput(const std::string &data)
{
    istringstream split(data);
    string token;

    while (split >> token)
        list.push_back(token);

    std::list<std::string>::iterator it = list.begin();
    for (; it != list.end(); it++)
    {

        if (std::strlen(it->c_str()) > 1)
            throw std::invalid_argument("Invalid argument!!");
        else if (!std::isdigit(it->c_str()[0]))
            if (IsOperator(it->c_str()[0]))
                throw std::invalid_argument("Error");
    }
}

void RPN::RPNCalculator(const std::string &data)
{
    double push;
    double rpnFirst;
    double rpnSecond;

    std::list<std::string>::iterator it = list.begin();
    for (; it != list.end(); it++)
    {

        if (!IsOperator(it->c_str()[0]))
        {
            if (st.size() < 2)
                throw std::invalid_argument("Error");
            rpnFirst = st.top();
            st.pop();
            rpnSecond = st.top();
            st.pop();
            if (it->c_str()[0] == '+')
                push = rpnFirst + rpnSecond;
            else if (it->c_str()[0] == '*')
                push = rpnFirst * rpnSecond;
            else if (it->c_str()[0] == '/')
            {
                if (rpnFirst == 0)
                    throw std::invalid_argument("Divided by zero!!");
                push = rpnSecond / rpnFirst;
            }
            else if (it->c_str()[0] == '-')
                push = rpnSecond - rpnFirst;
            st.push(push);
            continue;
        }
        st.push(std::atoi(it->c_str()));
    }
    if (st.size() > 1)
        std::invalid_argument("Error");
    std::cout << st.top() << "\n";
}

RPN::RPN(const std::string &data)
{
    try
    {
        parseInput(data);
        RPNCalculator(data);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
}