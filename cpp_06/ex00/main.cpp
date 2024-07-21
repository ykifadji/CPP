/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 16:03:24 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/21 16:04:01 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << RED"ERROR: Wrong number of arguments." DEF << std::endl;
		return 1;
	}
	try {
		std::string input = static_cast<std::string>(av[1]);
		ScalarConverter::convert(input);
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << DEF << std::endl;
	}
	return 0;
}