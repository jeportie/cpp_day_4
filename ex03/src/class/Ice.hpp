/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:08:26 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/21 19:27:45 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice 
:  public AMateria
{
public:
	Ice(void);
	Ice(std::string type);
	Ice(const Ice& src);

	virtual ~Ice(void);
	Ice&	operator=(const Ice& rhs);
	Ice*	clone() const;
	void	use(ICharacter& target);
};

#endif  // ********************************************************** ICE_HPP //
