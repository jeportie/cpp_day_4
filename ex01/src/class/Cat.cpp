/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:56:25 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 13:09:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>
#include "Cat.hpp"
#include "Animal.hpp"

/*const Animal* meta = new Animal();*/

Cat::Cat(void) : Animal()
{
	std::cout << "[Cat] - default constructor called - " << std::endl;
	Cat::setType("Cat");
	Cat::_brain;
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "[Cat] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Cat::~Cat(void)
{
	std::cout << "[Cat] - destructor called - " << std::endl;
	return;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "[Cat] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
		this->_type = rhs.getType();
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << _type << ": Meeeeoooowww..." << std::endl;
	return;
}
