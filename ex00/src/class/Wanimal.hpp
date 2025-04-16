/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wanimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:49:53 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 09:50:50 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WANIMAL_HPP
# define WANIMAL_HPP

# include <iostream>

class Wanimal
{
public:
	Wanimal(void);
	Wanimal(std::string const type);
	Wanimal(const Wanimal& src);
	~Wanimal(void);

	Wanimal& operator=(const Wanimal& rhs);

	std::string	 getType(void) const;
	void		 setType(std::string type);

	void makeSound(void) const;

protected:
	std::string _type;
};

// Overload operator<< for output streaming
std::ostream & operator<<(std::ostream& out, const Wanimal& in);

#endif  // ****************************************************** WANIMAL_HPP //
