/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DogTest.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:06:38 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 15:07:09 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/Dog.hpp"

// Test the default constructor of Dog
TEST(DogTest, DefaultConstructor)
{
    Dog dog;
    EXPECT_EQ(dog.getType(), "Dog");
	dog.pushIdea("This is a dog test");
	EXPECT_EQ(dog.getIdea(0), "This is a dog test");
}

// Test the copy constructor of Dog
TEST(DogTest, CopyConstructor)
{
    Dog original;
	original.pushIdea("This is a dog test");
    Dog copy(original);
	copy.pushIdea("This is 2");
    EXPECT_EQ(copy.getType(), "Dog");
	EXPECT_EQ(copy.getIdea(0), "This is a dog test");
	EXPECT_EQ(copy.getIdea(1), "This is 2");
	EXPECT_NE(original.getIdea(1), "This is 2");
}

// Test the assignment operator of Dog
TEST(DogTest, AssignmentOperator)
{
    Dog original;
    Dog copy;

	original.pushIdea("This is a dog test");
    copy = original;
	copy.pushIdea("This is 2");
    EXPECT_EQ(copy.getType(), "Dog");
	EXPECT_EQ(copy.getIdea(0), "This is a dog test");
	EXPECT_EQ(original.getIdea(0), "This is a dog test");
	EXPECT_EQ(copy.getIdea(1), "This is 2");
	EXPECT_NE(original.getIdea(1), "This is 2");
}


// Test the makeSound method of Dog
TEST(DogTest, MakeSound)
{
    Dog dog;
    testing::internal::CaptureStdout();
    dog.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Dog: Ouaf! Ouaf!...\n");
}

