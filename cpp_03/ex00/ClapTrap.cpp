/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:58:30 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/20 16:52:20 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : _name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::ClapTrap(const std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

ClapTrap::~ClapTrap(void) {}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout << _name << " took " << amount << " damage!" << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::attack(const std::string& target) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
		return ;
	std::cout << "ClapTrap" << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0 || _energyPoints <= 0)
		return ;
	std::cout << _name << " is repaired by " << amount << " points! Current hit points: " << _hitPoints << std::endl;
	_energyPoints--;
	_hitPoints += amount;
}
