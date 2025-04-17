/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) : _name("unnamed")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < _inventorySize; i++)
    {
        this->_inventory[i] = NULL;
    }
}

Character::Character(std::string const & name) : _name(name)
{
    std::cout << "Character name constructor called" << std::endl;
    for (int i = 0; i < _inventorySize; i++)
    {
        this->_inventory[i] = NULL;
    }
}

Character::Character(const Character& src)
{
    std::cout << "Character copy constructor called" << std::endl;
    this->_name = src._name;
    
    // Deep copy - first initialize all slots to NULL
    for (int i = 0; i < _inventorySize; i++)
    {
        this->_inventory[i] = NULL;
    }
    
    // Then clone each materia from the source
    for (int i = 0; i < _inventorySize; i++)
    {
        if (src._inventory[i] != NULL)
        {
            this->_inventory[i] = src._inventory[i]->clone();
        }
    }
}

Character::~Character(void)
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < _inventorySize; i++)
    {
        if (this->_inventory[i] != NULL)
        {
            delete this->_inventory[i];
            this->_inventory[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& rhs)
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name = rhs._name;
        
        // Delete existing materias
        for (int i = 0; i < _inventorySize; i++)
        {
            if (this->_inventory[i] != NULL)
            {
                delete this->_inventory[i];
                this->_inventory[i] = NULL;
            }
        }
        
        // Clone materias from source
        for (int i = 0; i < _inventorySize; i++)
        {
            if (rhs._inventory[i] != NULL)
            {
                this->_inventory[i] = rhs._inventory[i]->clone();
            }
        }
    }
    return *this;
}

std::string const & Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
        
    for (int i = 0; i < _inventorySize; i++)
    {
        if (this->_inventory[i] == NULL)
        {
            this->_inventory[i] = m;
            std::cout << this->_name << " equipped " << m->getType() << " in slot " << i << std::endl;
            return;
        }
    }
    
    std::cout << this->_name << "'s inventory is full, cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < _inventorySize && this->_inventory[idx] != NULL)
    {
        std::cout << this->_name << " unequipped " << this->_inventory[idx]->getType() << " from slot " << idx << std::endl;
        this->_inventory[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < _inventorySize && this->_inventory[idx] != NULL)
    {
        this->_inventory[idx]->use(target);
    }
    else
    {
        std::cout << this->_name << " has nothing to use in slot " << idx << std::endl;
    }
}
