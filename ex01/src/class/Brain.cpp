/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:56:22 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 12:57:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <ostream>
# include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[Brain] - default constructor called - " << std::endl;
}

Brain::Brain(const Brain& src)
{
	std::cout << "[Brain] - copy constructor called - " << std::endl;
	*this = src;
	return;
}

Brain::~Brain(void)
{
	std::cout << "[Brain] - destructor called - " << std::endl;
	return;
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "[Brain] - copy assignment operator called - " << std::endl;
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}
