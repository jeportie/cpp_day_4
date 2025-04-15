/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:55:35 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/15 14:47:59 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
public:
	Animal(void);
	Animal(std::string const type);
	Animal(const Animal& src);
	~Animal(void);

	Animal&		operator=(const Animal& rhs);

	std::string	getType(void) const;
	void		setType(std::string type);

	void		makeSound(void);

private:
	std::string _type;
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream& out, const Animal& in);

#endif  // ******************************************************* ANIMAL_HPP //
