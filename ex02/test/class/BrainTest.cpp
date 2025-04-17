/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BrainTest.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 07:53:38 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 08:47:02 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include "../../src/class/Brain.hpp"

// Test the default constructor of Brain
TEST(BrainTest, DefaultConstructor)
{
    Brain brain;
	
	brain.pushIdea("This is a Test");
    EXPECT_EQ(brain.getIdea(0), "This is a Test");
}

// Test the copy constructor of Brain
TEST(BrainTest, CopyConstructor)
{
    Brain original;
	original.pushIdea("This is a Test");
    Brain copy(original);
    EXPECT_EQ(copy.getIdea(0), "This is a Test");
}
