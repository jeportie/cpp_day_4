/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CureTest.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:03:43 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/22 09:04:56 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/Cure.hpp"

TEST(CureTest, DefaultConstructor)
{
    AMateria* materia = new Cure();
    EXPECT_EQ(materia->getType(), "cure");
}

TEST(CureTest, ParametricConstructor)
{
    const AMateria* materia = new Cure("test");
    EXPECT_EQ(materia->getType(), "test");
}

TEST(CureTest, CopyConstructor)
{
	Cure cure("copy");
    Cure copy(cure);
    EXPECT_EQ(copy.getType(), "copy");
}

TEST(CureTest, AssignmentOperator)
{
    Cure a("assign");
    Cure b;

    b = a;
    EXPECT_EQ(b.getType(), "assign");
}
