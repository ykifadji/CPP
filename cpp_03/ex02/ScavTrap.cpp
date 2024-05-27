/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:52:32 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/27 14:49:44 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default") {
	std::cout << GREEN "Constructor ScavTrap called." DEF << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	std::cout << GREEN "ScavTrap " << _name << " constructed." DEF << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap(cpy) {
	std::cout << GREEN "Copy ScavTrap constructor called." DEF << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& cpy) {
	if (this != &cpy)
		ClapTrap::operator=(cpy);
	std::cout << GREEN "Copy assignment operator called" DEF << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << RED "Destructor ScavTrap called." DEF << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << PURPLE "ScavTrap " << _name << " is now in Gate keeper mode." DEF << std::endl;
}
