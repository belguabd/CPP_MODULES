/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:33:07 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/07 19:34:14 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

void MateriaSource::learnMateria(AMateria *materia)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (!_storeMateria[i])
        {
            _storeMateria[i] = materia->clone();
            break;
        }

        i++;
    }
    delete materia;
}
AMateria *MateriaSource::createMateria(std::string const &type)
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (_storeMateria[i] && _storeMateria[i]->getType() == type)
            return _storeMateria[i]->clone();
        i++;
    }
    return (0);
}

MateriaSource::~MateriaSource()
{
    int i;

    i = 0;
    while (i < 4)
    {
        if (_storeMateria[i])
            delete _storeMateria[i];
        i++;
    }
}

MateriaSource::MateriaSource()
{
    int i;

    i = 0;

    while (i < 4)
    {
        _storeMateria[i] = NULL;
        i++;
    }
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    int i = 0;
    while (i < 4)
    {
        if (other._storeMateria[i])
            this->_storeMateria[i] = other._storeMateria[i]->clone();
        else
            this->_storeMateria[i] = NULL;
        i++;
    }
}
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    if (this == &other)
        return *this;
    int i = 0;
    while (i < 4)
    {
        delete _storeMateria[i];
        _storeMateria[i] = NULL;
        i++;
    }
    i = 0;
    while (i < 4)
    {
        if (other._storeMateria[i])
            _storeMateria[i] = other._storeMateria[i]->clone();
        i++;
    }
    return *this;
}
