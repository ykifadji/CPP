/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:29:06 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/28 10:07:08 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << GREEN "Constructor Brain called" DEF << std::endl;
}

Brain::Brain(const Brain& cpy) {
	std::cout << "Copy constructor Brain called." << std::endl;
	if (this != &cpy)
		*this = cpy;
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < _size; i++)
			_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << RED "Destructor Brain called" << std::endl;
}
