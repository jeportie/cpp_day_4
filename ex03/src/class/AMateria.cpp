/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:27:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/21 19:30:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria* AMateria::_removed[1024] = {NULL};
int AMateria::_emptyIndex = 0;
bool AMateria::_destroyed = false;

AMateria::AMateria(void)
: _wasEquiped(false)
{
    std::cout << "[AMateria] - default constructor called - " << std::endl;
	if (this->_destroyed == true)
		this->_destroyed = false;
    return;
}

AMateria::AMateria(const std::string& type)
: _wasEquiped(false)
{
    this->_type = type;
    std::cout << "[AMateria] - parametric constructor called - " << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
    std::cout << "[AMateria] - copy constructor called - " << std::endl;
    *this = src;
    return;
}

AMateria::~AMateria(void)
{
    std::cout << "[AMateria] - destructor called - " << std::endl;
	if (!this->_destroyed && this->_wasEquiped)
	{
		for (int i = 0; i < 1024; i++)
		{
			if (this->_removed[i])
				delete this->_removed[i];
		}
	}
	this->_destroyed = true;
    return;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    std::cout << "[AMateria] - copy assignment operator called - " << std::endl;
    if (this != &rhs)
	{
        this->_type = rhs.getType();
		this->_wasEquiped = rhs._wasEquiped;
	}
    return (*this);
}

const std::string& AMateria::getType() const { return _type; }


void AMateria::saveRemoved()
{
	if (_emptyIndex < 1024)
	{
		this->_removed[this->_emptyIndex] = this;
		this->_emptyIndex++;
		this->_wasEquiped = true;
	}
	else
	{
		std::cout << "Warning: Removed Materias array in full" << std::endl;
		delete this;
	}
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Using AMateria on " << target.getName() << std::endl;
}
