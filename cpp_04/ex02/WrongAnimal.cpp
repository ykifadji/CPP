/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:29:14 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/25 09:31:59 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << GREEN "Constructor WrongAnimal called." DEF << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy) {
	std::cout << GREEN "Copy Constructor WrongAnimal called." DEF << std::endl;
	this->type = cpy.type;
}

WrongAnimal::WrongAnimal(std::string type) : type(type) {
	std::cout << GREEN "Constructor WrongAnimal called." DEF << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& cpy) {
	if (this != &cpy)
		this->type = cpy.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << RED "Destructor WrongAnimal called." DEF << std::endl;
}

void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return this->type;
}
