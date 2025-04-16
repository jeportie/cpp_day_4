# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/16 14:48:08 by jeportie          #+#    #+#              #
#    Updated: 2025/04/16 15:09:08 by jeportie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.10)

project(Animals LANGUAGES CXX)

# Set C++ standard and compilation flags
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wshadow")

# Find all source files for the main executable
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "^${CMAKE_SOURCE_DIR}/build/.*")

# Define executable and sources
add_executable(${PROJECT_NAME} ${SOURCES} main.cpp)

# Set output directories to match your Makefile structure
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

### GOOGLE TEST INTEGRATION ###
enable_testing()

# Find GTest
find_package(GTest REQUIRED)
include(GoogleTest)

# Get source files for tests (excluding main.cpp)
file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Create AnimalTest executable
add_executable(AnimalTest 
    test/AnimalTest.cpp
    ${TEST_SOURCES}
)
target_link_libraries(AnimalTest GTest::GTest GTest::Main)
target_include_directories(AnimalTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Create CatTest executable
add_executable(CatTest 
    test/CatTest.cpp
    ${TEST_SOURCES}
)
target_link_libraries(CatTest GTest::GTest GTest::Main)
target_include_directories(CatTest PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Discover tests
gtest_discover_tests(AnimalTest)
gtest_discover_tests(CatTest)
