/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:58:30 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 13:02:45 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN "Constructor called." DEF << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN "ClapTrap " << _name << " constructed." DEF << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy) {
	*this = cpy;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& cpy) {
	if (this != &cpy) {
		this->_name = cpy._name;
		this->_hitPoints = cpy._hitPoints;
		this->_energyPoints = cpy._energyPoints;
		this->_attackDamage = cpy._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void) {
	std::cout << RED "Destructor called." DEF << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	std::cout << ORANGE << _name << " took " RED << amount << DEF ORANGE " damage!" DEF << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
		return ;
	std::cout << BLUE "ClapTrap" << _name << " attacks " << target << ", causing " CYAN << _attackDamage << BLUE " points of damage!" DEF << std::endl;
	_energyPoints--;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
		return ;
	_energyPoints--;
	_hitPoints += amount;
	std::cout << CYAN << _name << " is repaired by " << amount << " points! Current hit points: " GREEN << _hitPoints << DEF << std::endl;
}
