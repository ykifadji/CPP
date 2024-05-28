/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:42:16 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/28 18:51:53 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
	std::cout << GREEN "Constructor AAnimal called." DEF << std::endl;
}

AAnimal::AAnimal(const AAnimal& cpy) {
	std::cout << GREEN "Copy Constructor AAnimal called." DEF << std::endl;
	_type = cpy._type;
}

AAnimal::AAnimal(std::string type) : _type(type) {
	std::cout << GREEN "Constructor AAnimal called." DEF << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal& cpy) {
	if (this != &cpy)
		AAnimal::operator=(cpy);
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << RED "Destructor AAnimal called." DEF << std::endl;
}

std::string	AAnimal::getType() const {
	return _type;
}
