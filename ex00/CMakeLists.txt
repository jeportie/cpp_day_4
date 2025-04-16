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

# Find all .cpp sources starting from root, explicitly excluding 'build' directory
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "^${CMAKE_SOURCE_DIR}/build/.*")
list(FILTER SOURCES EXCLUDE REGEX "^${CMAKE_SOURCE_DIR}/tests/.*") # Exclude tests

# Define executable and sources
add_executable(${PROJECT_NAME} ${SOURCES})

# Set output directories to match your Makefile structure
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

### GOOGLE TEST INTEGRATION ###
enable_testing()

# Find GTest
find_package(GTest REQUIRED)
include(GoogleTest)

# Test executable
file(GLOB TEST_SOURCES "${CMAKE_SOURCE_DIR}/tests/*.cpp")

include(GoogleTest)
gtest_discover_tests(AnimalTest)
gtest_discover_tests(CatTest)
