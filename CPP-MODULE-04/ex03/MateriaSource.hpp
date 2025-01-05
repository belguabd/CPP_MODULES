/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belguabd <belguabd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:29:38 by belguabd          #+#    #+#             */
/*   Updated: 2024/10/07 19:04:39 by belguabd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *_storeMateria[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource &other);
    MateriaSource & operator=(const MateriaSource &other);
    ~MateriaSource();

    void learnMateria(AMateria *);
    AMateria *createMateria(std::string const &type);
};
