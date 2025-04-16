/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 13:56:54 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/15 13:58:39 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/Animal.hpp"
#include "src/class/Wanimal.hpp"
#include "src/class/Dog.hpp"
#include "src/class/Wcat.hpp"
#include "src/class/Cat.hpp"
#include <iostream>

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

const Wanimal* wmeta = new Wanimal();
const Wanimal* wi = new Wcat();

std::cout << wi->getType() << " " << std::endl;

wi->makeSound(); //will output the animal sound!
meta->makeSound();

// Clean up to avoid memory leaks
delete meta;
delete wmeta;
delete j;
delete i;
delete wi;

return 0;
}
