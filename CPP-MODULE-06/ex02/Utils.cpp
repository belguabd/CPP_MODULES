/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 10:17:11 by belguabd          #+#    #+#             */
/*   Updated: 2024/11/30 10:58:28 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

Base *generate(void)
{
    std::srand(std::time(0));
    int ran = std::rand() % 3;

    if (!ran)
        return (new A());
    if (ran == 1)
        return (new B());
    if (ran == 2)
        return (new C());
    return (NULL);
}

void identify(Base *p)
{
    A *Aptr = dynamic_cast<A *>(p);
    B *Bptr = dynamic_cast<B *>(p);
    C *Cptr = dynamic_cast<C *>(p);

    if (Aptr)
        std::cout << "The derived class is 'A'" << std::endl;
    else if (Bptr)
        std::cout << "The derived class is 'B'" << std::endl;
    else if (Cptr)
        std::cout << "The derived class is 'C'" << std::endl;
}

void identify(Base &p)
{
    try
    {
        A &Aptr = dynamic_cast<A &>(p);
        (void)Aptr;
        std::cout << "The derived class is 'A'" << std::endl;
    }
    catch (...)
    {
        try
        {
            B &Bptr = dynamic_cast<B &>(p);
            (void)Bptr;
            std::cout << "The derived class is 'B'" << std::endl;
        }
        catch (...)
        {
            try
            {
                C &Cptr = dynamic_cast<C &>(p);
                (void)Cptr;
                std::cout << "The derived class is 'C'" << std::endl;
            }
            catch (...)
            {
                std::cout << "The derived is unknown" << std::endl;
            }
        }
    }
}