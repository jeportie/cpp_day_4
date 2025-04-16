/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:56:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 13:57:27 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>
#include "Dog.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "[Dog] - default constructor called - " << std::endl;
	this->_type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal()
{
	std::cout << "[Dog] - copy constructor called - " << std::endl;
	this->_brain = new Brain(*src._brain);
	*this = src;
	return;
}

Dog::~Dog(void)
{
	std::cout << "[Dog] - destructor called - " << std::endl;
	delete this->_brain;
	return;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << _type << ": Ouaf! Ouaf!..." << std::endl;
	return;
}


