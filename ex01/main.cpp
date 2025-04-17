/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:56:54 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 09:15:23 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/Animal.hpp"
#include "src/class/Dog.hpp"
#include "src/class/Cat.hpp"
#include <iostream>

// Function to demonstrate basic polymorphism as required by the subject
void testBasicPolymorphism()
{
    std::cout << "\n===== BASIC POLYMORPHISM TEST =====\n" << std::endl;
    
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "j type: " << j->getType() << std::endl;
    std::cout << "i type: " << i->getType() << std::endl;

    std::cout << "\nMaking sounds:" << std::endl;
    std::cout << "i (Cat) sound: ";
    i->makeSound(); // will output the cat sound!
    std::cout << "j (Dog) sound: ";
    j->makeSound();
    std::cout << "meta (Animal) sound: ";
    meta->makeSound();

    std::cout << "\nCleaning up..." << std::endl;
    delete meta;
    delete j;
    delete i;
}

// Function to demonstrate deep copying with detailed explanation
void testDeepCopy()
{
    std::cout << "\n===== DEEP COPY TEST =====\n" << std::endl;
    
    std::cout << "Creating original dog..." << std::endl;
    Dog* originalDog = new Dog();
    originalDog->pushIdea("I want to chase the mailman");
    originalDog->pushIdea("I love bones");
    
    std::cout << "\nOriginal dog's ideas:" << std::endl;
    std::cout << "Idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog->getIdea(1) << std::endl;
    
    std::cout << "\nCreating a copy using the copy constructor..." << std::endl;
    Dog* copyDog = new Dog(*originalDog);
    
    std::cout << "\nVerifying copy has the same ideas:" << std::endl;
    std::cout << "Copy dog's idea 0: " << copyDog->getIdea(0) << std::endl;
    std::cout << "Copy dog's idea 1: " << copyDog->getIdea(1) << std::endl;
    
    std::cout << "\nModifying the copy's ideas (adding a new one)..." << std::endl;
    copyDog->pushIdea("I want to sleep");
    
    std::cout << "\nAfter modification:" << std::endl;
    std::cout << "Original dog's ideas (should be unchanged):" << std::endl;
    std::cout << "Idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog->getIdea(1) << std::endl;
    std::cout << "Idea 2: " << (originalDog->getIdea(2).empty() ? "<empty>" : originalDog->getIdea(2)) << std::endl;
    
    std::cout << "\nCopy dog's ideas (should have the new idea):" << std::endl;
    std::cout << "Idea 0: " << copyDog->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << copyDog->getIdea(1) << std::endl;
    std::cout << "Idea 2: " << copyDog->getIdea(2) << std::endl;
    
    std::cout << "\nTesting assignment operator..." << std::endl;
    Dog assignmentDog;
    assignmentDog = *originalDog;
    
    std::cout << "\nAssigned dog's ideas:" << std::endl;
    std::cout << "Idea 0: " << assignmentDog.getIdea(0) << std::endl;
    std::cout << "Idea 1: " << assignmentDog.getIdea(1) << std::endl;
    
    std::cout << "\nModifying assigned dog's ideas..." << std::endl;
    assignmentDog.pushIdea("I want to play fetch");
    
    std::cout << "\nOriginal dog's ideas (should still be unchanged):" << std::endl;
    std::cout << "Idea 0: " << originalDog->getIdea(0) << std::endl;
    std::cout << "Idea 1: " << originalDog->getIdea(1) << std::endl;
    std::cout << "Idea 2: " << (originalDog->getIdea(2).empty() ? "<empty>" : originalDog->getIdea(2)) << std::endl;
    
    std::cout << "\nAssigned dog's ideas (should have the new idea):" << std::endl;
    std::cout << "Idea 0: " << assignmentDog.getIdea(0) << std::endl;
    std::cout << "Idea 1: " << assignmentDog.getIdea(1) << std::endl;
    std::cout << "Idea 2: " << assignmentDog.getIdea(2) << std::endl;
    
    std::cout << "\nCleaning up..." << std::endl;
    delete originalDog;
    delete copyDog;
}

// Function to demonstrate array of animals as required by the subject
void testAnimalArray()
{
    std::cout << "\n===== ANIMAL ARRAY TEST =====\n" << std::endl;
    
    const int arraySize = 10;
    Animal* animals[arraySize];
    
    // Fill the array with Dogs and Cats (half and half)
    std::cout << "Creating an array of " << arraySize << " animals (half Dogs, half Cats)..." << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        if (i < arraySize / 2)
        {
            animals[i] = new Dog();
            std::cout << "Created Dog " << i << std::endl;
        }
        else
        {
            animals[i] = new Cat();
            std::cout << "Created Cat " << i << std::endl;
        }
    }
    
    // Make some sounds to demonstrate polymorphism
    std::cout << "\nDemonstrating polymorphism with makeSound()..." << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Animal " << i << " (" << animals[i]->getType() << "): ";
        animals[i]->makeSound();
    }
    
    // Delete all animals through the Animal* pointer (demonstrating proper destruction)
    std::cout << "\nDeleting animals through Animal pointers..." << std::endl;
    std::cout << "(Watch the destruction order in the output)" << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        std::cout << "Deleting animal " << i << " (" << animals[i]->getType() << ")..." << std::endl;
        delete animals[i];
    }
}

// Function to demonstrate memory leak checking
void testMemoryLeaks()
{
    std::cout << "\n===== MEMORY LEAK TEST =====\n" << std::endl;
    
    std::cout << "Creating a Dog and a Cat as Animal pointers..." << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << "\nDeleting through Animal pointers..." << std::endl;
    delete j; // should not create a leak
    delete i;
    
    std::cout << "\nIf no memory leaks, destructors should have been called in this order:" << std::endl;
    std::cout << "1. Dog destructor" << std::endl;
    std::cout << "2. Brain destructor (for Dog's brain)" << std::endl;
    std::cout << "3. Animal destructor (for Dog)" << std::endl;
    std::cout << "4. Cat destructor" << std::endl;
    std::cout << "5. Brain destructor (for Cat's brain)" << std::endl;
    std::cout << "6. Animal destructor (for Cat)" << std::endl;
}

int main()
{
    // Test basic polymorphism (from subject)
    testBasicPolymorphism();
    // Test deep copy (to verify deep copying works)
    testDeepCopy();
    // Test array of animals (from subject)
    testAnimalArray();
    // Test for memory leaks (from subject)
    testMemoryLeaks();
    std::cout << "\n===== ALL TESTS COMPLETED =====\n" << std::endl;
    return 0;
}
