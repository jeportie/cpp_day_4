/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:22:55 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/22 12:19:34 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include <iostream>

Character::Character(void)
: ICharacter()
{
	std::cout << "[Character] - default constructor called -" << std::endl;
	this->_name = "bob";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const std::string name)
: ICharacter()
{
	std::cout << "[Character] - parametric constructor called -" << std::endl;
	this->_name = name;	
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& src)
: ICharacter()
{
	std::cout << "[Character] - copy constructor called -" << std::endl;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	*this = src;	
}

Character::~Character(void)
{
	std::cout << "[Character] - destructor called -" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->inventory[i])
			delete this->inventory[i];
	}
	return ;
}

Character& Character::operator=(const Character& rhs)
{
	std::cout << "[Character] - copy assignement operator called -" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs.getName();
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
				delete this->inventory[i];
		}
		for (int i = 0; i < 4; i++)
		{
			if (rhs.inventory[i])
				this->inventory[i] = rhs.inventory[i]->clone();
			else
				this->inventory[i] = NULL;
		}
	}
	return (*this);
}

const std::string& Character::getName(void) const
{
	return (this->_name); 
}

void Character::equip(AMateria* m)
{
	int	i = 0;

	while (this->inventory[i])
		i++;
	if (i >= 4)
		return ;
	this->inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (!this->inventory[idx])
		return ;
	return ;
}

void Character::use(int idx, ICharacter& target)
{
	if (!this->inventory[idx])
		return ;
	this->inventory[idx]->use(target);
	return;
}
