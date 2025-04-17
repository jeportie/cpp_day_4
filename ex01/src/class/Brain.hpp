/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:56:11 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 08:33:57 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
class Brain
{
public:
	Brain(void);
	Brain(const Brain& src);
	~Brain(void);

	Brain&		operator=(const Brain& rhs);

	void		pushIdea(std::string const idea);
	std::string	getIdea(int i);

private:
	std::string _ideas[100];
};

#endif  // ******************************************************** BRAIN_HPP //
