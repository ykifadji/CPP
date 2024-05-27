/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:23:22 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/27 14:37:50 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << GREEN "Claptrap constructor called." DEF << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : _name(name), _hitPoints(10), 
												_energyPoints(10), _attackDamage(0) {
	std::cout << GREEN "ClapTrap " << _name << " constructed." DEF << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy) : _name(cpy._name), _hitPoints(cpy._hitPoints), 
		_energyPoints(cpy._energyPoints), _attackDamage(cpy._attackDamage) {
	std::cout << "Copy ClapTrap constructor called." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& cpy) {
	if (this != &cpy) {
		_name = cpy._name;
		_hitPoints = cpy._hitPoints;
		_energyPoints = cpy._energyPoints;
		_attackDamage = cpy._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << RED "Destructor ClapTrap called." DEF << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	std::cout << ORANGE << _name << " took " RED << amount << DEF ORANGE " damage!" DEF << std::endl;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
		return ;
	std::cout << BLUE << _name << " attacks " << target << ", causing " CYAN << _attackDamage << BLUE " points of damage!" DEF << std::endl;
	_energyPoints--;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoints <= 0) {
		std::cout << RED "He can't do anything !" DEF << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << CYAN << _name << " is repaired by " << amount << " points! Current hit points: " GREEN << _hitPoints << DEF << std::endl;
}
