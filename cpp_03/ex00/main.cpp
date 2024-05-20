/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:45:41 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/20 16:46:17 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void) {
	ClapTrap	myClapTrap("Bibi");

	myClapTrap.attack("Bob");
	myClapTrap.takeDamage(5);
	myClapTrap.beRepaired(1);

	myClapTrap.attack("Bill");
	myClapTrap.takeDamage(5);
	myClapTrap.attack("Bill");

	myClapTrap.beRepaired(1);
	myClapTrap.attack("Bill");

	for (int i = 0; i < 3; i++) {
		myClapTrap.beRepaired(1);
	}

	myClapTrap.attack("Bill");

	return (0);
}
