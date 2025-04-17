/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateroaTest.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:04:21 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 16:34:20 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../src/class/AMateria.hpp"

// GMock subclass of AMateria to provide a concrete instance
class MockMateria : public AMateria {
public:
    MockMateria() : AMateria() {}
    explicit MockMateria(const std::string& t) : AMateria(t) {}
    // Define the copy constructor
    MockMateria(const MockMateria& other) : AMateria(other) {}

    // Define the assignment operator
    MockMateria& operator=(const MockMateria& other) {
        if (this != &other) {
            AMateria::operator=(other);
        }
        return *this;
    }
    // Provide a mock implementation for the pure virtual clone()
    MOCK_CONST_METHOD0(clone, AMateria*());
    // use() inherits base implementation
};

TEST(AMateriaTest, DefaultConstructor) {
    MockMateria m;
    EXPECT_EQ(m.getType(), "");
}

TEST(AMateriaTest, ParametricConstructor) {
    MockMateria m("test");
    EXPECT_EQ(m.getType(), "test");
}

TEST(AMateriaTest, CopyConstructor) {
    MockMateria orig("copy");
    MockMateria copy(orig);
    EXPECT_EQ(copy.getType(), "copy");
}

TEST(AMateriaTest, AssignmentOperator) {
    MockMateria a("assign");
    MockMateria b;

    b = a;
    EXPECT_EQ(b.getType(), "assign");
}
