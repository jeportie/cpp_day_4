/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaTest.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:04:21 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/22 14:30:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <sstream>
#include "../../src/class/AMateria.hpp"
#include "../../src/class/ICharacter.hpp"

// Mock Character for testing use() method
class MockCharacter : public ICharacter {
public:
    MockCharacter(const std::string& name) : _name(name) {}
    
    virtual ~MockCharacter() {}
    
    virtual const std::string& getName() const {
        return _name;
    }
    
    virtual void equip(AMateria* m) {
        (void)m; // Unused in tests
    }
    
    virtual void unequip(int idx) {
        (void)idx; // Unused in tests
    }
    
    virtual void use(int idx, ICharacter& target) {
        (void)idx; // Unused in tests
        (void)target; // Unused in tests
    }
    
private:
    std::string _name;
};

// GMock subclass of AMateria to provide a concrete instance
class Mock : public AMateria
{
public:
    Mock()
    : AMateria()
    {}

    explicit Mock(const std::string& t)
    : AMateria(t)
	{}

    Mock(const Mock& other)
    : AMateria(other)
	{}

    Mock& operator=(const Mock& other)
    {
        if (this != &other)
        {
            AMateria::operator=(other);
        }
        return *this;
    }
    
    // Implementation of pure virtual method for testing
    virtual AMateria* clone() const {
        return new Mock(*this);
    }
};

TEST(AMateriaTest, DefaultConstructor)
{
    Mock m;
    EXPECT_EQ(m.getType(), "");
}

TEST(AMateriaTest, ParametricConstructor)
{
    Mock m("test");
    EXPECT_EQ(m.getType(), "test");
}

TEST(AMateriaTest, CopyConstructor)
{
    Mock orig("copy");
    Mock copy(orig);
    EXPECT_EQ(copy.getType(), "copy");
}

TEST(AMateriaTest, AssignmentOperator)
{
    Mock a("assign");
    Mock b;

    b = a;
    EXPECT_EQ(b.getType(), "assign");
}

// Test for getType method
TEST(AMateriaTest, GetType)
{
    Mock m("test_type");
    EXPECT_EQ(m.getType(), "test_type");
    
    const std::string& typeRef = m.getType();
    EXPECT_EQ(typeRef, "test_type");
}

// Test for clone method
TEST(AMateriaTest, Clone)
{
    Mock original("original");
    AMateria* cloned = original.clone();
    
    // Verify the clone has the same type
    EXPECT_EQ(cloned->getType(), original.getType());
    
    // Verify it's a different object
    EXPECT_NE(cloned, &original);
    
    delete cloned;
}

// Test for use method
TEST(AMateriaTest, Use)
{
    // Redirect cout to our stringstream
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    Mock m("test");
    MockCharacter target("target");
    
    m.use(target);
    
    // Restore cout
    std::cout.rdbuf(oldCout);
    
    // Check that the output contains the target name
    std::string output = buffer.str();
    EXPECT_TRUE(output.find("target") != std::string::npos);
}

// Test for saveRemoved method
TEST(AMateriaTest, SaveRemoved)
{
    Mock* m = new Mock("test");
    m->saveRemoved();
    
    Mock* trigger = new Mock("trigger");
    trigger->saveRemoved();
    
    delete trigger;
}

// Test for static array bounds
TEST(AMateriaTest, SaveRemovedBounds)
{
    std::stringstream buffer;
    std::streambuf* oldCout = std::cout.rdbuf(buffer.rdbuf());
    
    for (int i = 0; i < 5; i++) {
        Mock* m = new Mock("test");
        m->saveRemoved();
    }
    
    std::cout.rdbuf(oldCout);
}
