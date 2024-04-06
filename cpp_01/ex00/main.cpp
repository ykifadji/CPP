/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:15:12 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/05 10:42:27 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	Zombie	*new_zombie = newZombie("Foo");

	new_zombie->announce();
	delete new_zombie;
	randomChump("Bob");
	return 0;
}