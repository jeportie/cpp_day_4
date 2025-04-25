In C++ 98 the keyword **`virtual`** tells the compiler:

“When you call this member function (or destructor) through a **base-class pointer or reference**, pick the most-derived override 
that exists for the actual object you’re looking at—*even if you don’t know that object’s exact type at compile time*.”

That single rule enables **run-time (dynamic) polymorphism**.  
Here’s what’s happening under the hood and why it matters:

| Concept | What the `virtual` keyword triggers |
|---------|--------------------------------------|
| **Dynamic dispatch**     | The compiler creates a hidden “virtual table” (v-table) for each polymorphic class. Each virtual function gets a slot.     |
|                          |  At run time a base pointer carries a hidden v-pointer to the correct table, so the call is resolved *late* (at run time). |
| **Substitutability** | A reference/pointer of type `Base&` or `Base*` can refer to an object of any class derived from `Base` and still call the right override. |
| **Correct destructors** | Marking the base destructor `virtual` ensures `delete basePtr;` runs *both* the derived and base destructors, preventing leaks/UB. |
| **Interface definition** | Declaring a function `virtual` = 0 makes the class **abstract**; it cannot be instantiated and expresses “you must override this”. |

### Minimal illustration

```cpp
#include <iostream>

class Animal {
public:
    virtual void speak() const { std::cout << "Animal?\n"; }
    virtual ~Animal() {}              // always virtual in a polymorphic base
};

class Dog : public Animal {
public:
    void speak() const override { std::cout << "Woof!\n"; }
};

void make_it_talk(const Animal& a) {   // note: base reference
    a.speak();                         // dynamic dispatch
}

int main() {
    Dog d;
    make_it_talk(d);   // prints "Woof!", not "Animal?"
}
```

Without `virtual`, `Animal::speak()` would be chosen at compile time and you’d hear “Animal?” even when passing a `Dog`.

### Key take-aways

1. **Compile-time vs run-time** `virtual` moves binding from compile time (static) to run time (dynamic).
2. **Cost** Dynamic dispatch adds one indirection (v-table lookup) and prevents some inlining, but in C++ 98 it’s the canonical way to get OO polymorphism.
3. **Only through pointers/references** If you call a method on an object by value (e.g., `a.speak()` where `a` is an `Animal` variable), static binding is used because the compiler knows the exact type at compile time.
4. **Not for data** `virtual` applies only to member functions (and destructors), not data members.

So, in C++ 98, writing `virtual` is the signal that a function participates in polymorphism, enabling you to manipulate objects through their base types yet still get derived-class behaviour at run time.
