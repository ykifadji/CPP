/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:29:32 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/09 19:26:09 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(Weapon weapon, std::string name) : _weapon(weapon), _name(name) {
	return;
}

HumanA::HumanA(void) {
	return;
}

HumanA::~HumanA(void) {
	return;
}

void	HumanA::setName(std::string data) {
	this->_name = data;
	return;
}

void	HumanA::attack(void) {
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
	return;
}
