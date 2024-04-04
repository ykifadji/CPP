/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 14:43:08 by ykifadji          #+#    #+#             */
/*   Updated: 2024/03/25 15:25:49 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int	main(int ac, char **av) {

	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	for (int i = 1; i < ac; ++i)
		for (int j = 0; av[i][j]; ++j)
			std::cout << (char)toupper(av[i][j]);
	std::cout << std::endl;
	return (0);
}
