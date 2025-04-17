/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 15:26:35 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(void)
: _type("")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const& type)
: _type(type)
{
    std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = src;
}

AMateria::~AMateria(void) { std::cout << "AMateria destructor called" << std::endl; }

AMateria& AMateria::operator=(const AMateria& rhs)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_type = rhs._type;
    }
    return *this;
}

std::string const& AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter& target)
{
    std::cout << "* AMateria has no effect on " << target.getName() << " *" << std::endl;
}
