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
    std::cout << "==================== Test 1 ====================" << std::endl;
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
    std::cout << "==================== Test 2 ====================" << std::endl;
    MutantStack<int, std::vector<int> > mstackTest;
    mstackTest.push(5);
    mstackTest.push(17);
    std::cout << mstackTest.top() << std::endl;
    std::cout << "==================== Test 3 ====================" << std::endl;
    std::stack<int, std::vector<int> > stackTest(mstackTest);
    std::cout << stackTest.top() << std::endl;
    return 0;
}