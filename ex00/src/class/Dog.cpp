/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:56:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 09:55:05 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>
#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "[Dog] - default constructor called - " << std::endl;
	Dog::setType("Dog");
}

Dog::Dog(const Dog& src) : Animal()
{
	std::cout << "[Dog] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Dog::~Dog(void)
{
	std::cout << "[Dog] - destructor called - " << std::endl;
	return;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << _type << ": Ouaf! Ouaf!..." << std::endl;
	return;
}


