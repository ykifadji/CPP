/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:01:32 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/09 20:04:48 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) : _type(type) {
	return;
}

Weapon::Weapon(void) {
	return;
}

Weapon::~Weapon(void) {
	return;
}

std::string	Weapon::getType(void) const {
	return this->_type;
}

void	Weapon::setType(std::string data) {
	this->_type = data;
	return;
}
