/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:34:53 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/04 15:51:51 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
    std::cout << "================" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << "================" << std::endl;
    std::list<int> mlist;
    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << mlist.back() << std::endl;
    mlist.pop_back();
    std::cout << mlist.size() << std::endl;
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);
    std::list<int>::iterator it_list = mlist.begin();
    std::list<int>::iterator ite_list = mlist.end();
    ++it_list;
    --it_list;
    while (it_list != ite_list)
    {
        std::cout << *it_list << std::endl;
        ++it_list;
    }
    std::cout << "================" << std::endl;
    return (0);
}