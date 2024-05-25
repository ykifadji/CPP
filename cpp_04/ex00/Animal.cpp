/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:42:16 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/25 09:24:53 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << GREEN "Constructor Animal called." DEF << std::endl;
}

Animal::Animal(const Animal& cpy) {
	std::cout << GREEN "Copy Constructor Animal called." DEF << std::endl;
	this->type = cpy.type;
}

Animal::Animal(std::string type) : type(type) {
	std::cout << GREEN "Constructor Animal called." DEF << std::endl;
}

Animal&	Animal::operator=(const Animal& cpy) {
	if (this != &cpy)
		this->type = cpy.type;
	return *this;
}

Animal::~Animal() {
	std::cout << RED "Destructor Animal called." DEF << std::endl;
}

void	Animal::makeSound() const {
	std::cout << "Animal sound" << std::endl;
}

std::string	Animal::getType() const {
	return this->type;
}
