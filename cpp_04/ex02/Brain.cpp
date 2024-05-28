/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:29:06 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/25 09:23:23 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << GREEN "Constructor Brain called" DEF << std::endl;
}

Brain::Brain(const Brain& cpy) {
	std::cout << "Copy constructor Brain called." << std::endl;
	for (int i = 0; i < _size; i++)
		this->_ideas[i] = cpy._ideas[i];
}

Brain&	Brain::operator=(const Brain& other) {
	if (this != &other) {
		for (int i = 0; i < _size; i++)
			this->_ideas[i] = other._ideas[i];
	}
	return *this;
}

Brain::~Brain() {
	std::cout << RED "Destructor Brain called" << std::endl;
}
