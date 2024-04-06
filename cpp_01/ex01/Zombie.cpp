/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:39:17 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/05 12:24:34 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
	return ;
}

Zombie::~Zombie(void) {
	std::cout << BOLD RED << this->_name << " is destroyed." DEF << std::endl;
	return ;
}

void	Zombie::announce(void) const {

	std::cout << BOLD CYAN << this->_name << ": BraiiiiiiinnnzzzZ..." DEF << std::endl;
	return ;
}

void	Zombie::setName(std::string data) {
	this->_name = data;
}
