# C++ - Module 04

## Subtype Polymorphism, Abstract Classes, and

## Interfaces

_Summary: This document contains the exercises for Module 04 of the C++ modules._

```
Version: 11.
```

## Contents

- I Introduction
- II General rules
- III Exercise 00: Polymorphism
- IV Exercise 01: I don’t want to set the world on fire
- V Exercise 02: Abstract class
- VI Exercise 03: Interface & recap
- VII Submission and Peer Evaluation


# Chapter I

# Introduction

_C++ is a general-purpose programming language created by Bjarne Stroustrup as an ex-
tension of the C programming language, or "C with Classes" (source: Wikipedia)._

The goal of these modules is to introduce you to **Object-Oriented Programming**.
This will serve as the starting point of your C++ journey. Many languages are recom-
mended for learning OOP, but we’ve chosen C++ since it’s derived from your old friend
C. Because C++ is a complex language, and to keep things simple, your code will comply
with the C++98 standard.
We are aware that modern C++ differs significantly in many aspects. Therefore, if
you want to become a proficient C++ developer, it’s up to you to continue your journey
beyond the 42 Common Core!


# Chapter II

# General rules

**Compiling**

- Compile your code withc++and the flags-Wall -Wextra -Werror
- Your code should still compile if you add the flag-std=c++

```
Formatting and naming conventions
```
- The exercise directories will be named this way:ex00, ex01, ... , exn
- Name your files, classes, functions, member functions and attributes as required in
    the guidelines.
- Write class names in **UpperCamelCase** format. Files containing class code will
    always be named according to the class name. For instance:
    ClassName.hpp/ClassName.h,ClassName.cpp, orClassName.tpp. Then, if you
    have a header file containing the definition of a class "BrickWall" standing for a
    brick wall, its name will beBrickWall.hpp.
- Unless specified otherwise, every output message must end with a newline character
    and be displayed to the standard output.
- _Goodbye Norminette!_ No coding style is enforced in the C++ modules. You can
    follow your favorite one. But keep in mind that code your peer evaluators can’t
    understand is code they can’t grade. Do your best to write clean and readable code.

```
Allowed/Forbidden
```
```
You are not coding in C anymore. Time to C++! Therefore:
```
- You are allowed to use almost everything from the standard library. Thus, instead
    of sticking to what you already know, it would be smart to use the C++-ish versions
    of the C functions you are used to as much as possible.
- However, you can’t use any other external library. It means C++11 (and derived
    forms) andBoostlibraries are forbidden. The following functions are forbidden
    too:*printf(),*alloc()andfree(). If you use them, your grade will be 0 and
    that’s it.


C++ - Module 04 Subtype Polymorphism, Abstract Classes, and Interfaces

- Note that unless explicitly stated otherwise, theusing namespace <ns_name>and
    friendkeywords are forbidden. Otherwise, your grade will be -42.
- **You are allowed to use the STL only in Modules 08 and 09.** That means:
    no **Containers** (vector/list/map, and so forth) and no **Algorithms** (anything that
    requires including the<algorithm>header) until then. Otherwise, your grade will
    be -42.

```
A few design requirements
```
- Memory leakage occurs in C++ too. When you allocate memory (by using thenew
    keyword), you must avoid **memory leaks**.
- From Module 02 to Module 09, your classes must be designed in the **Orthodox**
    **Canonical Form, except when explicitly stated otherwise**.
- Any function implementation put in a header file (except for function templates)
    means 0 to the exercise.
- You should be able to use each of your headers independently from others. Thus,
    they must include all the dependencies they need. However, you must avoid the
    problem of double inclusion by adding **include guards**. Otherwise, your grade will
    be 0.

```
Read me
```
- You can add some additional files if you need to (i.e., to split your code). As these
    assignments are not verified by a program, feel free to do so as long as you turn in
    the mandatory files.
- Sometimes, the guidelines of an exercise look short but the examples can show
    requirements that are not explicitly written in the instructions.
- Read each module completely before starting! Really, do it.
- By Odin, by Thor! Use your brain!!!

```
Regarding the Makefile for C++ projects, the same rules as in C apply
(see the Norm chapter about the Makefile).
```
```
You will have to implement a lot of classes. This can seem tedious,
unless you’re able to script your favorite text editor.
```
```
You are given a certain amount of freedom to complete the exercises.
However, follow the mandatory rules and don’t be lazy. You would
miss a lot of useful information! Do not hesitate to read about
theoretical concepts.
```
# Chapter III

# Exercise 00: Polymorphism
```
Exercise : 00
```
```
Polymorphism
Turn-in directory : ex 00 /
Files to turn in :Makefile, main.cpp, *.cpp, *.{h, hpp}
Forbidden functions :None
```
For every exercise, you have to provide the **most complete tests** you can.
Constructors and destructors of each class must display specific messages. Don’t use the
same message for all classes.

Start by implementing a simple base class called **Animal**. It has one protected
attribute:

- std::string type;

```
Implement a Dog class that inherits from Animal.
Implement a Cat class that inherits from Animal.
```
These two derived classes must set theirtypefield depending on their name. Then,
the Dog’s type will be initialized to "Dog", and the Cat’s type will be initialized to "Cat".
The type of the Animal class can be left empty or set to the value of your choice.

```
Every animal must be able to use the member function:
makeSound()
It will print an appropriate sound (cats don’t bark).
```
Running this code should print the specific sounds of the Dog and Cat classes, not
the Animal’s.

```
int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
...
return 0;
}
```
To ensure you understood how it works, implement a **WrongCat** class that inherits
from a **WrongAnimal** class. If you replace the Animal and the Cat by the wrong ones
in the code above, the WrongCat should output the WrongAnimal sound.

```
Implement and turn in more tests than the ones given above.
```
