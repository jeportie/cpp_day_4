/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 13:10:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog& src);
	virtual ~Dog(void);

	Dog& operator=(const Dog& rhs);

	virtual void makeSound(void) const;

private:

	Brain* _brain;
};

#endif  // ********************************************************** DOG_HPP //
