/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateriaTest.cpp                                   :+:      :+:    :+:   */
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
    MOCK_CONST_METHOD0(clone, AMateria*());
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
