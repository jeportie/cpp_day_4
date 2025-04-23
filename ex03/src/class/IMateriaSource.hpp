/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 07:37:17 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/23 07:38:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual void      learnMateria(AMateria*)                = 0;
    virtual AMateria* createMateria(std::string const& type) = 0;
};

#endif  // *********************************************** IMATERIASOURCE_HPP //
