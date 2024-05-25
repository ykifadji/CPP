/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:19:10 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/25 17:10:12 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), _brain(new Brain()) {
	std::cout << GREEN "Constructor Dog called." DEF << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal(cpy), _brain(new Brain(*cpy._brain)) {
	std::cout << GREEN "Copy constructor Dog called." DEF << std::endl;
	this->type = cpy.type;
}

Dog&	Dog::operator=(const Dog& cpy) {
	if (this != &cpy) {
		this->type = cpy.type;
		if (_brain)
			delete _brain;
		_brain = new Brain(*cpy._brain);
	}
	return *this;
}

Dog::~Dog() {
	std::cout << RED "Destructor Dog called." DEF << std::endl;
	delete _brain;
}

void	Dog::makeSound() const {
	std::cout << BLUE "Woof Woof! 🐶" DEF << std::endl;
}
