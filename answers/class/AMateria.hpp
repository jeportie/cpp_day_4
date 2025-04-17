/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 15:06:55 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

// Forward declaration to avoid circular dependency
class ICharacter;

class AMateria
{
protected:
    std::string _type;

public:
    AMateria(void);
    AMateria(std::string const & type);
    AMateria(const AMateria& src);
    virtual ~AMateria(void);

    AMateria& operator=(const AMateria& rhs);

    std::string const & getType() const; // Returns the materia type
    
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif // ******************************************************* AMATERIA_HPP //
