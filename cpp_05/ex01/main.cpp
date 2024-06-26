/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:41:23 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/26 18:03:29 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void) {
	try {
		// Bureaucrat	TooLowGrade("TooLow", 200);
		// Bureaucrat	TooHighGrade("TooHigh", 0);
		Bureaucrat	Joe("Joe", 1);
		Bureaucrat	Bob("Bob", 150);
		Bureaucrat	Will("Will", 5);

		std::cout << Joe << std::endl;
		std::cout << Bob << std::endl;
		std::cout << Will << std::endl;

		std::cout << ORANGE"*********************SUCCESSFULL GRADE INCREMENTATION**********************" DEF << std::endl;
		Will.incrGrade();
		std::cout << Will << std::endl;
		std::cout << std::endl;

		std::cout << ORANGE"*********************SUCCESSFULL GRADE DECREMENTATION**********************" DEF << std::endl;
		Will.decrGrade();
		std::cout << Will << std::endl;
		std::cout << std::endl;

		std::cout << ORANGE"*****TRYING TO INCREMENT GRADE WHEN IT IS ALREADY THE HIGHEST POSSIBLE*****" DEF << std::endl;
		try {
			Joe.incrGrade();
		} catch (std::exception& e) {
			std::cout << RED << "Failed to increment " << Joe.getName() << "'s grade because " << e.what() << DEF << std::endl;
		}
		std::cout << std::endl;

		std::cout << ORANGE"*****TRYING TO DECREMENT GRADE WHEN IT IS ALREADY THE LOWEST POSSIBLE******" DEF << std::endl;
		try {
			Bob.decrGrade();
		} catch (std::exception& e) {
			std::cout << RED << "Failed to decrement " << Joe.getName() << "'s grade because " << e.what() << DEF << std::endl;
		}
		std::cout << std::endl;
	} catch (std::exception& e) {
		std::cout << RED << e.what() << DEF << std::endl;
	}
	return 0;
}
