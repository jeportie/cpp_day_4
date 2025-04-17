/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:34:59 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 16:22:49 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
protected:
	std::string	_type;

public:
	AMateria(void);
	AMateria(const std::string& type);
	AMateria(const AMateria& src);

	virtual ~AMateria(void);

	AMateria& operator=(const AMateria& rhs);

	const std::string&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
};

#endif  // ***************************************************** AMATERIA_HPP //
