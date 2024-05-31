/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:27:15 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/24 08:26:43 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << GREEN "Constructor WrongCat called." DEF << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal(cpy) {
	std::cout << GREEN "Copy constructor WrongCat called." DEF << std::endl;
	this->type = cpy.type;
}

WrongCat&	WrongCat::operator=(const WrongCat& cpy) {
	if (this != &cpy)
		WrongAnimal::operator=(cpy);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << RED "Destructor WrongCat called." DEF << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << ORANGE "Miaouw 😺 Miaouuw! 🙀" DEF << std::endl;
}
