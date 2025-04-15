/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:12:16 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/15 15:12:18 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>

class Cat
{
public:
	Cat(void);
	Cat(const Cat& src);
	~Cat(void);

	Cat& operator=(const Cat& rhs);

private:
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream& out, const Cat& in);

#endif  // ********************************************************** CAT_HPP //
