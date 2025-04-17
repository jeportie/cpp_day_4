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
#include "../src/class/Cat.hpp"

// Test the default constructor of Cat
TEST(CatTest, DefaultConstructor)
{
    Cat cat;
    EXPECT_EQ(cat.getType(), "Cat");
}

// Test the copy constructor of Cat
TEST(CatTest, CopyConstructor)
{
    Cat original;
    Cat copy(original);
    EXPECT_EQ(copy.getType(), "Cat");
}

// Test the assignment operator of Cat
TEST(CatTest, AssignmentOperator)
{
    Cat original;
    Cat copy;
    copy = original;
    EXPECT_EQ(copy.getType(), "Cat");
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
