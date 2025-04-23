/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 07:39:51 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/23 07:51:52 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource
: public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& src);

	virtual ~MateriaSource(void);

	MateriaSource& operator=(const MateriaSource& rhs);

    void      learnMateria(AMateria* materia);
    AMateria* createMateria(std::string const& type);

private:
	AMateria* Materias[4];
};

#endif  // ************************************************ MATERIASOURCE_HPP //
