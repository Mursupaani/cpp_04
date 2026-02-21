/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpollan <anpollan@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 15:18:48 by anpollan          #+#    #+#             */
/*   Updated: 2026/02/21 17:42:05 by anpollan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	AMateria* clone;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	clone = tmp->clone();

	std::cout << "Original: " << tmp->getType() << std::endl;
	std::cout << "Clone: " << clone->getType() << std::endl;
	delete clone;
	tmp = src->createMateria("cure");
	clone = tmp->clone();
	std::cout << "Original: " << tmp->getType() << std::endl;
	std::cout << "Clone: " << clone->getType() << std::endl;
	std::cout << "\n";
	delete clone;
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "\n";
	me->unequip(0);
	me->use(0, *bob);
	me->use(-1, *bob);
	me->use(4, *bob);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(0, *bob);
	std::cout << "\n";
	me->unequip(0);
	me->unequip(0);
	me->unequip(1);
	me->unequip(1);

	delete bob;
	delete me;
	delete src;
	return 0;
}
