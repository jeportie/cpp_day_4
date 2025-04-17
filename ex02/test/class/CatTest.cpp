/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CatTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:06:38 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 15:07:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/Cat.hpp"

// Test the default constructor of Cat
TEST(CatTest, DefaultConstructor)
{
    Cat cat;
    EXPECT_EQ(cat.getType(), "Cat");
	cat.pushIdea("This is a cat test");
	EXPECT_EQ(cat.getIdea(0), "This is a cat test");
}

// Test the copy constructor of Cat
TEST(CatTest, CopyConstructor)
{
    Cat original;
	original.pushIdea("This is a cat test");
    Cat copy(original);
	copy.pushIdea("This is 2");
    EXPECT_EQ(copy.getType(), "Cat");
	EXPECT_EQ(copy.getIdea(0), "This is a cat test");
	EXPECT_EQ(copy.getIdea(1), "This is 2");
	EXPECT_NE(original.getIdea(1), "This is 2");
}

// Test the assignment operator of Cat
TEST(CatTest, AssignmentOperator)
{
    Cat original;
    Cat copy;

	original.pushIdea("This is a cat test");
    copy = original;
	copy.pushIdea("This is 2");
    EXPECT_EQ(copy.getType(), "Cat");
	EXPECT_EQ(copy.getIdea(0), "This is a cat test");
	EXPECT_EQ(original.getIdea(0), "This is a cat test");
	EXPECT_EQ(copy.getIdea(1), "This is 2");
	EXPECT_NE(original.getIdea(1), "This is 2");
}

// Test the makeSound method of Cat
TEST(CatTest, MakeSound)
{
    Cat cat;
    testing::internal::CaptureStdout();
    cat.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Cat: Meeeeoooowww...\n");
}
