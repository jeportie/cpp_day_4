/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSourceTest.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:46:13 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/23 14:36:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/MateriaSource.hpp"
#include "../../src/class/AMateria.hpp"
#include "../../src/class/Ice.hpp"

TEST(MateriaSourceTest, DefaultConstructor)
{
    MateriaSource s;
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(NULL, s.getMateria(i));
}

TEST(MateriaSourceTest, CopyConstructor)
{
    MateriaSource original;
    MateriaSource copy;
	for (int i = 0; i < 4; i++)
		EXPECT_EQ(NULL, copy.getMateria(i));
}

TEST(MateriaSourceTest, AssignmentOperator)
{
    MateriaSource a;
    MateriaSource b;
	AMateria* materiaTest = new Ice();    
	
	b.learnMateria(materiaTest);
    a = b;
	EXPECT_EQ("ice", b.getMateria(0)->getType());
	EXPECT_TRUE(a.getMateria(0) != NULL);
	EXPECT_EQ("ice", a.getMateria(0)->getType());
}

TEST(MateriaSourceTest, LearnMateria)
{
    MateriaSource a;
	AMateria* materiaTest = new Ice();    
	a.learnMateria(materiaTest);
	EXPECT_EQ("ice", a.getMateria(0)->getType());
}

TEST(MateriaSourceTest, createMateria)
{
	AMateria* test;

    MateriaSource a;
	AMateria* materiaTest = new Ice();    
	a.learnMateria(materiaTest);
	test = a.createMateria("ice");
	EXPECT_EQ("ice", test->getType());
}
