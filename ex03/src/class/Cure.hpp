/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 08:25:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/22 09:00:38 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
#include <string>

class Cure
: public AMateria
{
public:
	Cure(void);
	Cure(std::string const type);
	Cure(const Cure& src);

	virtual ~Cure(void);

	Cure&	operator=(const Cure& rhs);
	Cure*	clone() const;
	void	use(ICharacter& target);
};

#endif  // ********************************************************* CURE_HPP //
