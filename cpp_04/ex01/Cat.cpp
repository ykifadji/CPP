/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:41:18 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/24 08:26:20 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
	std::cout << GREEN "Constructor Cat called." DEF << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy) {
	std::cout << GREEN "Copy constructor Cat called." DEF << std::endl;
	this->type = cpy.type;
}

Cat&	Cat::operator=(const Cat& cpy) {
	if (this != &cpy)
		Animal::operator=(cpy);
	return *this;
}

Cat::~Cat() {
	std::cout << RED "Destructor Cat called." DEF << std::endl;
}

void	Cat::makeSound() const {
	std::cout << ORANGE "Miaouw 😺 Miaouuw! 🙀" DEF << std::endl;
}
