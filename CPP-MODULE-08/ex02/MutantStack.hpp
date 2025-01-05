/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:40:18 by belguabd          #+#    #+#             */
/*   Updated: 2024/12/04 15:47:37 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <list>

template <typename T>

class MutantStack : public std::stack<T>
{
public:
    MutantStack();
    MutantStack(const MutantStack &src);
    MutantStack &operator=(const MutantStack &src);
    ~MutantStack();

    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator  begin() { return std::stack<T>::c.begin(); }
    iterator end() { return std::stack<T>::c.end(); }

    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator begin() const { return std::stack<T>::c.begin(); }
    const_iterator end() const { return std::stack<T>::c.end(); }
};

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &src) : std::stack<T>(src) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
    if (this != &src)
    {
        std::stack<T>::operator=(src);
    }
    return *this;
}

template <typename T>
MutantStack<T>::~MutantStack() {}

