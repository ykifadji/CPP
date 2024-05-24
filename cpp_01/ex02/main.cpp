/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 07:54:43 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/24 07:55:15 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main() {
	std::string	str = "HI THIS IS BRAIN";
	std::string&	strRef = str;
	std::string*	strPtr = &str;

	std::cout << &str << std::endl;
	std::cout << strPtr << std::endl;
	std::cout << &strRef << std::endl;

	std::cout << str << std::endl;
	std::cout << *strPtr << std::endl;
	std::cout << strRef << std::endl;
	return 0;
}
