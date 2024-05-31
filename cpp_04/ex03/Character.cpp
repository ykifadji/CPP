/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:08:39 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/31 09:34:01 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("Default") {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& cpy) : _name(cpy._name) {
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			_inventory[i] = cpy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character::Character(std::string const & name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character&	Character::operator=(const Character& other) {
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character() {
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

std::string const &	Character::getName() const {return _name;}

void	Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return ;
		}
	}
}

void	Character::unequip(int idx) {
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx <= 3 && _inventory[idx])
		_inventory[idx]->use(target);
	else
		std::cout << "No materia in slot " << idx << " to use." << std::endl;
}
