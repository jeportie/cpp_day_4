/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:20:00 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 14:20:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* _templates[4];
    static const int _templateSize = 4;

public:
    MateriaSource(void);
    MateriaSource(const MateriaSource& src);
    virtual ~MateriaSource(void);

    MateriaSource& operator=(const MateriaSource& rhs);

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif // ************************************************* MATERIASOURCE_HPP //