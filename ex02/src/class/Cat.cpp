/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:56:25 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 13:56:13 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>
#include "Cat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

/*const Animal* meta = new Animal();*/

Cat::Cat(void) : Animal()
{
	std::cout << "[Cat] - default constructor called - " << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
	std::cout << "[Cat] - copy constructor called - " << std::endl;
	this->_brain = NULL;
	*this = src;
	return;
}

Cat::~Cat(void)
{
	std::cout << "[Cat] - destructor called - " << std::endl;
	delete this->_brain;
	return;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "[Cat] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
	{
		this->_type = rhs.getType();
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << _type << ": Meeeeoooowww..." << std::endl;
	return;
}

void Cat::pushIdea(std::string const idea)
{
	this->_brain->pushIdea(idea);
	return ;
}

std::string Cat::getIdea(int i) { return (this->_brain->getIdea(i)); }
