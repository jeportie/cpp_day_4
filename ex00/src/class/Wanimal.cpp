/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wanimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:51:05 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 09:57:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <ostream>
# include "Wanimal.hpp"

Wanimal::Wanimal(void)
: _type("Wanimal")
{
	std::cout << "[Wanimal] - default constructor called - " << std::endl;
}

Wanimal::Wanimal(std::string const type)
: _type(type)
{
	std::cout << "[Wanimal] - parametric constructor called -" << std::endl;
}

Wanimal::Wanimal(const Wanimal& src)
{
	std::cout << "[Wanimal] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Wanimal::~Wanimal(void)
{
	std::cout << "[Wanimal] - destructor called - " << std::endl;
	return;
}

Wanimal& Wanimal::operator=(const Wanimal& rhs)
{
	std::cout << "[Wanimal] - copy assignment operator called -" << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

std::ostream & operator<<(std::ostream & out, const Wanimal& in)
{
	out << "The value of _type is : " << in.getType();
	return (out);
}

std::string Wanimal::getType(void) const { return (_type); }

void Wanimal::setType(std::string type) { _type = type; }

void Wanimal::makeSound(void) const
{
	std::cout << _type << ": ** Unknown Sound ** ..." << std::endl;
	return;
}
