/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSourceTest.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:46:13 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/23 14:19:21 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/MateriaSource.hpp"
#include "../../src/class/AMateria.hpp"
#include "../../src/class/Ice.hpp"

TEST(CharacterTest, DefaultConstructor)
{
    MateriaSource s;
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(NULL, s.getMateria(i));
}

TEST(CharacterTest, CopyConstructor)
{
    MateriaSource original;
    MateriaSource copy;
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(NULL, copy.getMateria(i));
}

TEST(CharacterTest, AssignmentOperator)
{
    MateriaSource a;
    MateriaSource b;
	AMateria* materiaTest = new Ice();    
	
	b.learnMateria(materiaTest);
    a = b;
	EXPECT_EQ("ice", b.getMateria(0)->getType());
	EXPECT_TRUE(a.getMateria(0) != NULL);
	EXPECT_EQ("", a.getMateria(0)->getType());
}
