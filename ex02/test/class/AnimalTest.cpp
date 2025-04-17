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
#include "../../src/class/Animal.hpp"
#include "../../src/class/Dog.hpp"
#include "../../src/class/Cat.hpp"

// Since Animal is now an abstract class, we can't test it directly
// Instead, we'll test its derived classes

// Test that we can use Animal pointers for polymorphism
TEST(AnimalTest, Polymorphism)
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    EXPECT_EQ(dog->getType(), "Dog");
    EXPECT_EQ(cat->getType(), "Cat");
    
    // Clean up
    delete dog;
    delete cat;
}

// Test that makeSound works through the Animal interface
TEST(AnimalTest, MakeSoundPolymorphism)
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    
    testing::internal::CaptureStdout();
    dog->makeSound();
    std::string dogOutput = testing::internal::GetCapturedStdout();
    EXPECT_EQ(dogOutput, "Dog: Ouaf! Ouaf!...\n");
    
    testing::internal::CaptureStdout();
    cat->makeSound();
    std::string catOutput = testing::internal::GetCapturedStdout();
    EXPECT_EQ(catOutput, "Cat: Meeeeoooowww...\n");
    
    // Clean up
    delete dog;
    delete cat;
}
