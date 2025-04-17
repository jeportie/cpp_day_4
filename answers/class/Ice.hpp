/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
public:
    Ice(void);
    Ice(const Ice& src);
    virtual ~Ice(void);

    Ice& operator=(const Ice& rhs);

    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif // *********************************************************** ICE_HPP //