/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeportie <jeportie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 14:13:59 by jeportie          #+#    #+#             */
/*   Updated: 2025/04/17 14:14:00 by jeportie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/class/AMateria.hpp"
/*#include "src/class/Cure.hpp"*/
/*#include "src/class/Ice.hpp"*/
#include "src/class/ICharacter.hpp"
#include "src/class/Character.hpp"

int main()
{
    /*IMateriaSource* src = new MateriaSource();*/
    /*src->learnMateria(new Ice());*/
    /*src->learnMateria(new Cure());*/

    ICharacter* me = new Character("me");

    /*AMateria*   tmp;*/
    /*tmp = src->createMateria("ice");*/
    /*me->equip(tmp);*/
    /*tmp = src->createMateria("cure");*/
    /*me->equip(tmp);*/

    ICharacter* bob = new Character("bob");

    me->use(0, *bob);
    me->use(1, *bob);

    delete bob;
    delete me;
    /*delete src;*/

    return 0;
}
