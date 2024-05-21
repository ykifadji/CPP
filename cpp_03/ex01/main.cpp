/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:12:01 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 15:29:08 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) {
	ScavTrap scav("Scavvy");

	scav.attack("target");
	scav.takeDamage(25);
	scav.beRepaired(15);
	scav.guardGate();

	return (0);
}