/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wcat.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:58:58 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 09:59:42 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>
#include "Wcat.hpp"
#include "Wanimal.hpp"

Wcat::Wcat(void) : Wanimal()
{
	std::cout << "[Wcat] - default constructor called - " << std::endl;
	Wcat::setType("Wcat");
}

Wcat::Wcat(const Wcat& src) : Wanimal(src)
{
	std::cout << "[Wcat] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Wcat::~Wcat(void)
{
	std::cout << "[Wcat] - destructor called - " << std::endl;
	return;
}

Wcat & Wcat::operator=(const Wcat& rhs)
{
	std::cout << "[Wcat] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void Wcat::makeSound(void) const
{
	std::cout << _type << ": Meeeeoooowww..." << std::endl;
	return;
}

