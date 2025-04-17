/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < _templateSize; i++)
    {
        this->_templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    
    // Initialize all slots to NULL first
    for (int i = 0; i < _templateSize; i++)
    {
        this->_templates[i] = NULL;
    }
    
    // Deep copy - clone each materia from source
    for (int i = 0; i < _templateSize; i++)
    {
        if (src._templates[i] != NULL)
        {
            this->_templates[i] = src._templates[i]->clone();
        }
    }
}

MateriaSource::~MateriaSource(void)
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < _templateSize; i++)
    {
        if (this->_templates[i] != NULL)
        {
            delete this->_templates[i];
            this->_templates[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &rhs)
    {
        // Delete existing templates
        for (int i = 0; i < _templateSize; i++)
        {
            if (this->_templates[i] != NULL)
            {
                delete this->_templates[i];
                this->_templates[i] = NULL;
            }
        }
        
        // Clone templates from source
        for (int i = 0; i < _templateSize; i++)
        {
            if (rhs._templates[i] != NULL)
            {
                this->_templates[i] = rhs._templates[i]->clone();
            }
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return;
        
    for (int i = 0; i < _templateSize; i++)
    {
        if (this->_templates[i] == NULL)
        {
            this->_templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    
    std::cout << "MateriaSource can't learn more materias, memory is full" << std::endl;
    delete m; // Delete the materia if we can't store it
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < _templateSize; i++)
    {
        if (this->_templates[i] != NULL && this->_templates[i]->getType() == type)
        {
            std::cout << "MateriaSource created " << type << std::endl;
            return this->_templates[i]->clone();
        }
    }
    
    std::cout << "MateriaSource doesn't know type: " << type << std::endl;
    return NULL;
}
