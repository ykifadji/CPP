/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:27:30 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/09 18:28:57 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void) {
	return;
}

HumanB::~HumanB(void) {
	return;
}

void	HumanB::setName(std::string data) {
	this->_name = data;
	return;
}

void	HumanB::attack(void) {
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
	return;
}
