/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 17:00:09 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/28 17:00:30 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	MateriaSource src;
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();

	src.learnMateria(ice);
	src.learnMateria(cure);

	AMateria* createdIce = src.createMateria("ice");
	AMateria* createdCure = src.createMateria("cure");

	delete createdIce;
	delete createdCure;

	return 0;
}