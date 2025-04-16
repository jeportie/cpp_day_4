/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:12:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 13:05:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat& src);
	virtual ~Cat(void);

	Cat& operator=(const Cat& rhs);

	virtual void makeSound(void) const;
private:

	Brain* brain;
};

#endif  // ********************************************************** CAT_HPP //
