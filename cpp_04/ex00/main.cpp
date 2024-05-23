/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:57:29 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/23 14:13:11 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* test = new WrongCat();
	const Dog* k = new Dog();
	const Cat* l = new Cat();
	const WrongCat* m = new WrongCat();

	std::cout << std::endl << YELLOW "object j name is " << j->getType() << " " << DEF << std::endl;
	std::cout << BLUE "object i name is " << i->getType() << DEF << std::endl;
	std::cout << RED "object test name is " << test->getType() << DEF << std::endl;
	std::cout << YELLOW "object k name is " << k->getType() << DEF << std::endl;
	std::cout << BLUE "object l name is " << l->getType() << DEF << std::endl;
	std::cout << BLUE "object m name is " << m->getType() << DEF << std::endl;
	std::cout << "Call of makeSound() function from i: ";
	i->makeSound();
	std::cout << "Call of makeSound() function from j: ";
	j->makeSound();
	std::cout << "Call of makeSound() function from meta: ";
	meta->makeSound();
	std::cout << "Call of makeSound() function from test: ";
	test->makeSound();
	std::cout << "Call of makeSound() function from k:  ";
	k->makeSound();
	std::cout << "Call of makeSound() function from l: ";
	l->makeSound();
	std::cout << "Call of makeSound() function from m: ";
	m->makeSound();
	std::cout << std::endl;
	delete test;
	delete i;
	delete j;
	delete meta;
	return (0);
}
