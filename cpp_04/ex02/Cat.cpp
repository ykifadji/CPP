/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:41:18 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/25 17:10:18 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
	std::cout << GREEN "Constructor Cat called." DEF << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy), _brain(new Brain(*cpy._brain)) {
	std::cout << GREEN "Copy constructor Cat called." DEF << std::endl;
	this->type = cpy.type;
}

Cat&	Cat::operator=(const Cat& cpy) {
	if (this != &cpy) {
		Animal::operator=(cpy);
		if (_brain)
			delete _brain;
		_brain = new Brain(*cpy._brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << RED "Destructor Cat called." DEF << std::endl;
	delete _brain;
}

void	Cat::makeSound() const {
	std::cout << ORANGE "Miaouw 😺 Miaouuw! 🙀" DEF << std::endl;
}
