### Polymorphism in C++

Polymorphism is one of the four pillars of Object-Oriented Programming (along with Encapsulation, Inheritance, and Abstraction). It allows objects of different classes to be treated as objects of a common base class.

**Types of Polymorphism:**
1. **Compile-time Polymorphism (Static)**: Achieved through function overloading and operator overloading
2. **Runtime Polymorphism (Dynamic)**: Achieved through function overriding and virtual functions

In this exercise, we're focusing on runtime polymorphism using virtual functions.

**How Virtual Functions Work:**
- When a function is declared as `virtual` in a base class, C++ creates a virtual function table (vtable)
- Each object has a hidden pointer to its class's vtable
- When a virtual function is called through a base class pointer, the vtable is used to determine which function to call

**Example:**
```cpp
Animal* animal = new Dog();
animal->makeSound(); // Calls Dog::makeSound(), not Animal::makeSound()
```

### Deep vs. Shallow Copying

**Shallow Copy:**
- Copies only the member variables
- If a class has pointers, only the pointer addresses are copied, not the data they point to
- Both objects end up pointing to the same memory

**Deep Copy:**
- Copies both the member variables and the data pointed to by pointers
- Each object has its own independent copy of the data
- Changes to one object don't affect the other

**Why Deep Copy is Important:**
- Prevents memory leaks and double-free errors
- Ensures objects are truly independent
- Required for proper resource management

**How to Implement Deep Copy:**
1. Allocate new memory for pointer members in the copy constructor and assignment operator
2. Copy the data from the source object to the newly allocated memory
3. Ensure proper cleanup in the destructor

