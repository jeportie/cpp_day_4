/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:05:36 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/23 14:22:42 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource(void)
: IMateriaSource()
{
	std::cout << "[MateriaSource] - default constructor called - " << std::endl;
	for (int i = 0; i < 4; i++)
		this->Materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
: IMateriaSource(src)
{
	std::cout << "[MateriaSource] - copy constructor called - " << std::endl;
	for (int i = 0; i < 4; i++)
		this->Materias[i] = NULL;
	*this = src;
}	
	
MateriaSource::~MateriaSource(void)
{
	std::cout << "[MateriaSource] - destructor called - " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->Materias[i])
			delete this->Materias[i];
	}
	return;
}

MateriaSource & MateriaSource::operator=(const MateriaSource& rhs)
{
	std::cout << "[MateriaSource] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->Materias[i])
				delete this->Materias[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (rhs.Materias[i])
				this->Materias[i] = rhs.Materias[i]->clone();
			else
				this->Materias[i] = NULL;
		}

	}
	return (*this);
}	


void MateriaSource::learnMateria(AMateria* materia)
{
	int	i = 0;

	while (this->Materias[i])
		i++;
	if (i > 3)
		return;
	this->Materias[i] = materia;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (type == this->Materias[i]->getType())
			return (this->Materias[i]->clone());
	}
	return (NULL);
}

AMateria* MateriaSource::getMateria(int i) const
{
	if (i < 0 || i > 3)
		return(NULL);
	return (this->Materias[i]);
}
