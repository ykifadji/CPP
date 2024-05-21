/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:52:32 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 15:32:01 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("default", 100, 50, 20) {
	std::cout << GREEN "Constructor ScavTrap called." DEF << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name, 100, 50, 20) {
	std::cout << GREEN "ScavTrap " << _name << " constructed." DEF << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& cpy) : ClapTrap(cpy) {
	std::cout << GREEN "Copy ScavTrap constructor called." DEF << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& cpy) {
	ClapTrap::operator=(cpy);
	std::cout << GREEN "Copy assignment operator called" DEF << std::endl;
	return *this;
}

ScavTrap::~ScavTrap(void) {
	std::cout << RED "Destructor called." DEF << std::endl;
}

void	ScavTrap::guardGate(void) {
	std::cout << PURPLE "ScavTrap " << _name << " is now in Gate keeper mode." DEF << std::endl;
}
