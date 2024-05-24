/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:12:01 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/24 16:30:30 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) {

	std::cout << "Testing ClapTrap" << std::endl;
	ClapTrap clap("Clappy");

	clap.attack("target1");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\nTesting FragTrap" << std::endl;
	FragTrap frag("Fraggy");

	frag.attack("target3");
	frag.takeDamage(20);
	frag.beRepaired(15);
	frag.highFivesGuys();

	std::cout << "\nAdditional Tests" << std::endl;

	std::cout << "\nTesting FragTrap taking critical damage" << std::endl;
	FragTrap frag2("Fraggy2");
	frag2.takeDamage(110);
	frag2.beRepaired(5);
	frag2.highFivesGuys();

	return 0;
}