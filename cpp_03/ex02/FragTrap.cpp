/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:49:06 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/27 14:50:40 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default") {
	std::cout << GREEN "Constructor FragTrap called." DEF << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	std::cout << GREEN "FragTrap " << _name << " constructed." DEF << std::endl;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
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
