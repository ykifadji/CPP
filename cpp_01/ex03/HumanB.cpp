/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:27:30 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/19 11:13:26 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	return;
}

HumanB::~HumanB(void) {
	return;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
	return;
}

void	HumanB::attack(void) {
	std::cout << this->_name << " attacks with their " << _weapon->getType() << std::endl;
	return;
}
