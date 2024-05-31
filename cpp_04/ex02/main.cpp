/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:53:38 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/28 19:01:33 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
	const int SIZE = 10;
	AAnimal* animals[SIZE];

	for (int i = 0; i < SIZE / 2; ++i)
		animals[i] = new Dog();

	for (int i = SIZE / 2; i < SIZE; ++i)
		animals[i] = new Cat();

	for (int i = 0; i < SIZE; ++i)
		animals[i]->makeSound();

	for (int i = 0; i < SIZE; ++i)
		delete animals[i];

	return 0;
}
