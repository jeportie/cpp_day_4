/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AnimalTest.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:04:21 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/16 15:06:31 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../src/class/Animal.hpp"

// Test the default constructor of Animal
TEST(AnimalTest, DefaultConstructor)
{
    Animal animal;
    EXPECT_EQ(animal.getType(), "Animal");
}

// Test the parametric constructor of Animal
TEST(AnimalTest, ParametricConstructor)
{
    Animal animal("Dog");
    EXPECT_EQ(animal.getType(), "Dog");
}

// Test the copy constructor of Animal
TEST(AnimalTest, CopyConstructor)
{
    Animal original;
    Animal copy(original);
    EXPECT_EQ(copy.getType(), "Animal");
}

// Test the makeSound method of Animal
TEST(AnimalTest, MakeSound)
{
    Animal animal;
    testing::internal::CaptureStdout();
    animal.makeSound();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Animal: ** Unknown Sound ** ...\n");
}
