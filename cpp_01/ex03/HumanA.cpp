/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:29:32 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/19 09:11:09 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon){
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
