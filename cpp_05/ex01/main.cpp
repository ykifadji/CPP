/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:41:23 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/27 09:00:17 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 42);
		Bureaucrat joe("Joe", 1); // Highest grade
		Bureaucrat will("Will", 150); // Lowest grade
		
		Form formA("FormA", 50, 100);
		Form formB("FormB", 1, 1);

		std::cout << std::endl << bob << std::endl;
		std::cout << joe << std::endl;
		std::cout << will << std::endl;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl << std::endl;

		std::cout << MAGBACK GREEN"\t\t[Test to sign forms]" DEF << std::endl;
		bob.signForm(formA);
		joe.signForm(formB);
		will.signForm(formA);

		std::cout << std::endl << DEF BLUE"FormA signed status: " DEF << (formA.getSigned() ? GREEN"Signed ✅" DEF : RED"Not signed ❌" DEF) << std::endl;
		std::cout << BLUE"FormB signed status: " DEF << (formB.getSigned() ? GREEN"Signed ✅" DEF : RED"Not signed ❌" DEF) << std::endl;
		
		std::cout << std::endl << MAGBACK GREEN"\t[Test to sign FormB with Bob (should throw exception)]" DEF << std::endl;
		bob.signForm(formB);
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}

