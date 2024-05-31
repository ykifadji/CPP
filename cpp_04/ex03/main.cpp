/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:00:09 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/31 09:57:56 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

void testMateriaCreation() {
	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	AMateria* ice = src.createMateria("ice");
	AMateria* cure = src.createMateria("cure");
	AMateria* unknown = src.createMateria("unknown");

	std::cout << "Testing Materia Creation:" << std::endl;
	std::cout << "Ice: " << (ice ? "Created" : "Not Created") << std::endl;
	std::cout << "Cure: " << (cure ? "Created" : "Not Created") << std::endl;
	std::cout << "Unknown: " << (unknown ? "Created" : "Not Created") << std::endl;

	delete ice;
	delete cure;
	delete unknown;
}

void testCharacterEquipAndUse() {
	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	Character* me = new Character("Me");
	Character* bob = new Character("Bob");

	AMateria* ice = src.createMateria("ice");
	AMateria* cure = src.createMateria("cure");

	me->equip(ice);
	me->equip(cure);

	std::cout << "\nTesting Character Equip and Use:" << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);
	me->use(0, *bob);

	delete ice;
	delete cure;
	delete me;
	delete bob;
}

void testMateriaSourceMemoryManagement() {
	MateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	MateriaSource* srcCopy = new MateriaSource(*src);
	MateriaSource assigned;
	assigned = *src;

	delete src;

	std::cout << "\nTesting MateriaSource Memory Management:" << std::endl;
	AMateria* ice = srcCopy->createMateria("ice");
	AMateria* cure = assigned.createMateria("cure");

	std::cout << "Ice: " << (ice ? "Created" : "Not Created") << std::endl;
	std::cout << "Cure: " << (cure ? "Created" : "Not Created") << std::endl;

	delete srcCopy;
	delete ice;
	delete cure;
}

int main() {
	testMateriaCreation();
	testCharacterEquipAndUse();
	testMateriaSourceMemoryManagement();

	return 0;
}
