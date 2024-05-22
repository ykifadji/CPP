/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:49:06 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 19:55:36 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default", 100, 100, 30) {
	std::cout << GREEN "Constructor FragTrap called." DEF << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name, 100, 100, 30) {
	std::cout << GREEN "FragTrap " << _name << " constructed." DEF << std::endl;
}

FragTrap::FragTrap(const FragTrap& cpy) : ClapTrap(cpy) {
	std::cout << GREEN "Copy FragTrap constructor called." DEF << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& cpy) {
	if (this != &cpy)
		ClapTrap::operator=(cpy);
	std::cout << GREEN "Copy assignment operator called" DEF << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << RED "Destructor FragTrap called." DEF << std::endl;
}

void	FragTrap::highFivesGuys() {
	std::cout << YELLOW "FragTrap " << _name << " requests high fives! ✋" DEF << std::endl;
}
