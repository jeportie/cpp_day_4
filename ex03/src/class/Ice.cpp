/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:15:39 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/22 13:05:40 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <string>

Ice::Ice(void)
: AMateria()
{
	std::cout << "[Ice] - default constructor called -" << std::endl;
	this->_type = "ice";
}

Ice::Ice(std::string type)
: AMateria(type)
{
	std::cout << "[Ice] - parametric constructor called -" << std::endl;
	this->_type = type;
}


Ice::Ice(const Ice& src)
: AMateria(src)
{
	std::cout << "[Ice] - copy constructor called -" << std::endl;
	*this = src;
}

Ice::~Ice(void)
{
	std::cout << "[Ice] - destructor called -" << std::endl;
	return ;
}

Ice& Ice::operator=(const Ice& rhs)
{
	std::cout << "[Ice] - copy assignement operator called -" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}


Ice* Ice::clone() const
{
	Ice *clone = new Ice(*this);

	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; 
	(void)target;
	return ;
}
