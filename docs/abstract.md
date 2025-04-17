# Lesson on Abstract Classes in C++

Now that we've made the necessary changes to make the Animal class abstract, let's understand what abstract classes are and why they're useful.

### What is an Abstract Class?

An abstract class in C++ is a class that cannot be instantiated directly. It serves as a base class for other derived classes. Abstract classes are used to define a common interface for a set of derived classes.

A class becomes abstract when it has at least one pure virtual function. A pure virtual function is a virtual function that is declared with the `= 0` syntax.

### Why Use Abstract Classes?

1. **Interface Definition**: Abstract classes define a common interface that derived classes must implement.
2. **Prevent Instantiation**: Sometimes, a base class doesn't make sense to instantiate directly. Making it abstract prevents this.
3. **Polymorphism**: Abstract classes enable polymorphic behavior through pointers or references to the base class.

### Key Characteristics of Abstract Classes

1. **Cannot be Instantiated**: You cannot create objects of an abstract class.
2. **Can Have Constructors**: Even though you can't instantiate an abstract class directly, it can have constructors that are called by derived classes.
3. **Can Have Data Members**: Abstract classes can have data members that are inherited by derived classes.
4. **Can Have Regular Methods**: Besides pure virtual functions, abstract classes can have regular methods with implementations.
5. **Must Be Subclassed**: To use an abstract class, you must create a derived class that implements all pure virtual functions.

### Pure Virtual Functions

A pure virtual function is declared by using the `= 0` syntax:

```cpp
virtual void makeSound() const = 0;
```

This tells the compiler that:
1. This function must be overridden by any concrete (non-abstract) derived class.
2. There is no implementation of this function in the base class.

### Abstract Classes vs. Interfaces

In C++, there's no explicit "interface" keyword like in some other languages. Instead, abstract classes with only pure virtual functions serve as interfaces. However, abstract classes can also have:

1. Data members
2. Implemented methods
3. Constructors and destructors

This makes them more flexible than pure interfaces in languages like Java or C#.

