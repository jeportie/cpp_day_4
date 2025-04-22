/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:46:45 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/22 13:05:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include <iostream>

Cure::Cure(void)
: AMateria()
{
	std::cout << "[CURE] - default constructor called -" << std::endl;
	this->_type = "cure";
}

Cure::Cure(std::string type)
: AMateria(type)
{
	std::cout << "[CURE] - parametric constructor called -" << std::endl;
	this->_type = type;
}

Cure::Cure(const Cure& src)
: AMateria(src)
{
	std::cout << "[CURE] - copy constructor called -" << std::endl;
	*this = src;
}

Cure::~Cure(void)
{
	std::cout << "[CURE] - destrucor called -" << std::endl;
	return ;
}

Cure& Cure::operator=(const Cure& rhs)
{
	std::cout << "[CURE] - copy assignement operator called -" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

Cure* Cure::clone() const
{
	Cure *clone = new Cure(*this);
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; 
	(void)target;
	return ;
}
