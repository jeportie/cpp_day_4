/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IceTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:04:21 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/21 19:30:22 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/Ice.hpp"

TEST(IceTest, DefaultConstructor)
{
    AMateria* materia = new Ice();
    EXPECT_EQ(materia->getType(), "ice");
}

TEST(IceTest, ParametricConstructor)
{
    const AMateria* materia = new Ice("test");
    EXPECT_EQ(materia->getType(), "test");
}

TEST(IceTest, CopyConstructor)
{
	Ice ice("copy");
    Ice copy(ice);
    EXPECT_EQ(copy.getType(), "copy");
}

TEST(IceTest, AssignmentOperator)
{
    Ice a("assign");
    Ice b;

    b = a;
    EXPECT_EQ(b.getType(), "assign");
}
