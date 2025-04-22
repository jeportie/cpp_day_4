/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CharacterTest.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:35:10 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/22 14:35:10 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <sstream>
#include "../../src/class/Character.hpp"
#include "../../src/class/Ice.hpp"
#include "../../src/class/Cure.hpp"

TEST(CharacterTest, DefaultConstructor)
{
    Character c;
    EXPECT_EQ(c.getName(), "bob");
}

TEST(CharacterTest, ParametricConstructor)
{
    Character c("test");
    EXPECT_EQ(c.getName(), "test");
}

TEST(CharacterTest, CopyConstructor)
{
    Character original("original");
    Character copy(original);
    EXPECT_EQ(copy.getName(), "original");
}

TEST(CharacterTest, AssignmentOperator)
{
    Character a("a");
    Character b("b");
    
    b = a;
    EXPECT_EQ(b.getName(), "a");
}

TEST(CharacterTest, GetName)
{
    Character c("test");
    EXPECT_EQ(c.getName(), "test");
    
    const std::string& nameRef = c.getName();
    EXPECT_EQ(nameRef, "test");
}

TEST(CharacterTest, EquipAndUse)
{
    // Redirect cout to our stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    Character c("test");
    AMateria* ice = new Ice();
    
    // Test equip
    c.equip(ice);
    
    // Test use
    c.use(0, c);
    
    // Restore cout
    std::cout.rdbuf(oldCout);
    
    // Check that the output contains the expected ice attack message
    std::string output = buffer.str();
    EXPECT_TRUE(output.find("shoots an ice bolt at test") != std::string::npos);
}

TEST(CharacterTest, EquipMultiple)
{
    Character c("test");
    AMateria* ice1 = new Ice();
    AMateria* ice2 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* cure2 = new Cure();
    AMateria* extra = new Ice(); // This one shouldn't be equipped
    
    c.equip(ice1);
    c.equip(ice2);
    c.equip(cure1);
    c.equip(cure2);
    c.equip(extra); // Should do nothing as inventory is full
    
    // Redirect cout to our stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    // Test all slots
    c.use(0, c); // Should use ice1
    c.use(1, c); // Should use ice2
    c.use(2, c); // Should use cure1
    c.use(3, c); // Should use cure2
    
    // Restore cout
    std::cout.rdbuf(oldCout);
    
    // Check output for all four uses
    std::string output = buffer.str();
    int iceCount = 0;
    int cureCount = 0;
    
    size_t pos = 0;
    while ((pos = output.find("shoots an ice bolt", pos)) != std::string::npos) {
        iceCount++;
        pos++;
    }
    
    pos = 0;
    while ((pos = output.find("heals", pos)) != std::string::npos) {
        cureCount++;
        pos++;
    }
    
    EXPECT_EQ(iceCount, 2);
    EXPECT_EQ(cureCount, 2);
    
    // Clean up the extra materia that wasn't equipped
    delete extra;
}

TEST(CharacterTest, Unequip)
{
    Character c("test");
    AMateria* ice = new Ice();
    
    c.equip(ice);
    
    // Unequip the materia
    c.unequip(0);
    
    // Redirect cout to our stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    // Try to use the unequipped slot
    c.use(0, c);
    
    // Restore cout
    std::cout.rdbuf(oldCout);
    
    // Check that nothing was output (since the slot is empty)
    std::string output = buffer.str();
    EXPECT_TRUE(output.empty());
    
    // The materia should have been saved as removed, so we don't need to delete it
}

TEST(CharacterTest, UnequipInvalidSlot)
{
    Character c("test");
    
    // Try to unequip from an empty slot
    c.unequip(0); // Should do nothing
    c.unequip(5); // Should do nothing (invalid index)
    
    // If we don't crash, the test passes
}

TEST(CharacterTest, UseInvalidSlot)
{
    Character c("test");
    
    // Redirect cout to our stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    // Try to use an empty slot
    c.use(0, c); // Should do nothing
    c.use(5, c); // Should do nothing (invalid index)
    
    // Restore cout
    std::cout.rdbuf(oldCout);
    
    // Check that nothing was output
    std::string output = buffer.str();
    EXPECT_TRUE(output.empty());
}

TEST(CharacterTest, DeepCopy)
{
    // Redirect cout to our stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    // Create and set up original character
    Character original("original");
    original.equip(new Ice());
    original.equip(new Cure());
    
    // Create a copy
    Character copy = original;
    
    // Modify original
    original.unequip(0);
    
    // Test that copy still has both materias
    copy.use(0, copy); // Should still use Ice
    copy.use(1, copy); // Should still use Cure
    
    // Restore cout
    std::cout.rdbuf(oldCout);
    
    // Check output for both uses in the copy
    std::string output = buffer.str();
    EXPECT_TRUE(output.find("shoots an ice bolt") != std::string::npos);
    EXPECT_TRUE(output.find("heals") != std::string::npos);
}

TEST(CharacterTest, CopyConstructorDeepCopy)
{
    // Redirect cout to our stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    // Create and set up original character
    Character original("original");
    original.equip(new Ice());
    original.equip(new Cure());
    
    // Create a copy using copy constructor
    Character copy(original);
    
    // Modify original
    original.unequip(0);
    
    // Test that copy still has both materias
    copy.use(0, copy); // Should still use Ice
    copy.use(1, copy); // Should still use Cure
    
    // Restore cout
    std::cout.rdbuf(oldCout);
    
    // Check output for both uses in the copy
    std::string output = buffer.str();
    EXPECT_TRUE(output.find("shoots an ice bolt") != std::string::npos);
    EXPECT_TRUE(output.find("heals") != std::string::npos);
}
