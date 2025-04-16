/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:55:42 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/15 15:16:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <iostream>
# include <ostream>
# include "Animal.hpp"

Animal::Animal(void)
: _type("Animal")
{
	std::cout << "[Animal] - default constructor called -" << std::endl;
}

Animal::Animal(std::string const type)
: _type(type)
{
	std::cout << "[Animal] - parametric constructor called -" << std::endl;
}

Animal::Animal(const Animal& src)
{
	std::cout << "[Animal] - copy constructor called -" << std::endl;
	*this = src;
	return;
}

Animal::~Animal(void) { std::cout << "[Animal] - destructor called -" << std::endl; }

Animal & Animal::operator=(const Animal& rhs)
{
	std::cout << "[Animal] - copy assignment operator called -" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::ostream & operator<<(std::ostream & out, const Animal& in)
{
	out << "The value of _type is : " << in.getType();
	return (out);
}

std::string Animal::getType(void) const { return (_type); }

void Animal::setType(std::string type) { _type = type; }

void Animal::makeSound(void) const
{
	std::cout << _type << ": ** Unknown Sound ** ..." << std::endl;
	return;
}
