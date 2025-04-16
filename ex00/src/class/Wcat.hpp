/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wcat.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:57:47 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 09:58:47 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCAT_HPP
# define WCAT_HPP

#include "Wanimal.hpp"

class Wcat : public Wanimal
{
public:
	Wcat(void);
	Wcat(const Wcat& src);
	~Wcat(void);

	Wcat& operator=(const Wcat& rhs);

	void makeSound(void) const;
};

#endif  // ********************************************************* WCAT_HPP //
