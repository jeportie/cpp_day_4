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
#include "../src/class/Dog.hpp"

// Test the default constructor of Dog
TEST(DogTest, DefaultConstructor)
{
    Dog cat;
    EXPECT_EQ(cat.getType(), "Dog");
}

// Test the copy constructor of Dog
TEST(DogTest, CopyConstructor)
{
    Dog original;
    Dog copy(original);
    EXPECT_EQ(copy.getType(), "Dog");
}

// Test the assignment operator of Dog
TEST(DogTest, AssignmentOperator)
{
    Dog original;
    Dog copy;
    copy = original;
    EXPECT_EQ(copy.getType(), "Dog");
}

// Test the makeSound method of Dog
TEST(DogTest, MakeSound)
{
    Dog cat;
    testing::internal::CaptureStdout();
    cat.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Dog: Ouaf! Ouaf!...\n");
}

