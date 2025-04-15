/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:07 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/15 16:13:06 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>

class Dog
{
public:
	Dog(void);
	Dog(const Dog& src);
	~Dog(void);

	Dog& operator=(const Dog& rhs);

private:
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream& out, const Dog& in);

#endif  // ********************************************************** DOG_HPP //
