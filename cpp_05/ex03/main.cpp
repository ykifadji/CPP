/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:41:23 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/16 15:20:23 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int	main() {
	try {
		Intern someRandomIntern;
		Bureaucrat	Joe("Joe", 1);
		AForm* rrf;
		
		std::cout << std::endl;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << std::endl;
		if (rrf != NULL)
			std::cout << *rrf << std::endl;
		std::cout << std::endl;
		Joe.signForm(*rrf);
		Joe.executeForm(*rrf);
		delete rrf;
	} catch (std::exception& e) {
		std::cout << RED << e.what() << DEF << std::endl;
	}
	return 0;
}
