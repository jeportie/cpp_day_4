# CMAKE generated file: DO NOT EDIT!
# Generated by CMake Version 3.25
cmake_policy(SET CMP0009 NEW)

# SOURCES at CMakeLists.txt:23 (file)
file(GLOB_RECURSE NEW_GLOB LIST_DIRECTORIES false "/root/projects/cpp_day_4/ex00/*.cpp")
set(OLD_GLOB
  "/root/projects/cpp_day_4/ex00/build/CMakeFiles/3.25.1/CompilerIdCXX/CMakeCXXCompilerId.cpp"
  "/root/projects/cpp_day_4/ex00/main.cpp"
  "/root/projects/cpp_day_4/ex00/src/class/Animal.cpp"
  "/root/projects/cpp_day_4/ex00/src/class/Cat.cpp"
  "/root/projects/cpp_day_4/ex00/src/class/Dog.cpp"
  "/root/projects/cpp_day_4/ex00/src/class/Wanimal.cpp"
  "/root/projects/cpp_day_4/ex00/src/class/Wcat.cpp"
  "/root/projects/cpp_day_4/ex00/test/AnimalTest.cpp"
  "/root/projects/cpp_day_4/ex00/test/CatTest.cpp"
  )
if(NOT "${NEW_GLOB}" STREQUAL "${OLD_GLOB}")
  message("-- GLOB mismatch!")
  file(TOUCH_NOCREATE "/root/projects/cpp_day_4/ex00/build/CMakeFiles/cmake.verify_globs")
endif()
