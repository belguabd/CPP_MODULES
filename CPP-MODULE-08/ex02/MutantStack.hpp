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
#include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
public:
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack &src) : std::stack<T, Container>(src) {};
    MutantStack &operator=(const MutantStack &src)
    {
        if (this != &src)
            std::stack<T, Container>::operator=(src);
        return *this;
    }
    ~MutantStack() {}
    typedef typename Container::iterator iterator;
    iterator begin() { return std::stack<T, Container>::c.begin(); }
    iterator end() { return std::stack<T, Container>::c.end(); }

    typedef typename Container::const_iterator const_iterator;
    const_iterator begin() const { return std::stack<T, Container>::c.begin(); }
    const_iterator end() const { return std::stack<T, Container>::c.end(); }
};