/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:56:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/15 16:13:14 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include <iostream>
# include <ostream>
# include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "[Dog] - default constructor called - " << std::endl;
}

Dog::Dog(const Dog& src)
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

Dog & Dog::operator=(const Dog& rhs)
{
	std::cout << "[Dog] - copy assignment operator called - " << std::endl;
//	if (this != &rhs)
//		this->_foo = rhs.getFoo();
	return (*this);
}

//std::ostream & operator<<(std::ostream & out, const Dog& in)
//{
	//out << "The value of _foo is : " << in.getFoo();
	//return (out);
//}

