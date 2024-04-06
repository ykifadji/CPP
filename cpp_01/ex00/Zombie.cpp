/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:30:34 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/05 10:22:55 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << BOLD GREEN << this->_name << " is create" DEF << std::endl;
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
