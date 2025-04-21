/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:27:46 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/21 19:30:29 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <ostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void)
{
    std::cout << "[AMateria] - default constructor called - " << std::endl;
    return;
}

AMateria::AMateria(const std::string& type)
{
    this->_type = type;
    std::cout << "[AMateria] - parametric constructor called - " << std::endl;
}

AMateria::AMateria(const AMateria& src)
{
    std::cout << "[AMateria] - copy constructor called - " << std::endl;
    *this = src;
    return;
}

AMateria::~AMateria(void)
{
    std::cout << "[AMateria] - destructor called - " << std::endl;
    return;
}

AMateria& AMateria::operator=(const AMateria& rhs)
{
    std::cout << "[AMateria] - copy assignment operator called - " << std::endl;
    if (this != &rhs)
        this->_type = rhs.getType();
    return (*this);
}

const std::string& AMateria::getType() const { return _type; }

void AMateria::use(ICharacter& target)
{
    std::cout << "Using AMateria on " << target.getName() << std::endl;
}
