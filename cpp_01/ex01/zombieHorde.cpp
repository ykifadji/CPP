/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:41:06 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/05 12:23:48 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie*	zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		zombieHorde[i].setName(name);
		zombieHorde[i].announce();
	}
	return zombieHorde;
}
