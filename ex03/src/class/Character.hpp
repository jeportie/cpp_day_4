/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:16:02 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/22 11:58:01 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <string>

class Character 
: ICharacter
{
public:
	Character(void);
	Character(const std::string name);
	Character(const Character& src);

	virtual ~Character(void);

	Character& operator=(const Character& rhs);

	const std::string& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
private:
	std::string _name;
	AMateria* inventory[4];
};

#endif  // **************************************************** CHARACTER_HPP //
