/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:00:09 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/29 10:49:12 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

int main() {
	MateriaSource src;
	src.learnMateria(new Ice());
	src.learnMateria(new Cure());

	Character* me = new Character("Me");
	Character* bob = new Character("Bob");

	AMateria* tmp;
	tmp = src.createMateria("ice");
	me->equip(tmp);
	tmp = src.createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	me->unequip(0);

	delete me;
	delete bob;

	return 0;
}
