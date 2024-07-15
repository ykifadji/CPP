/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 17:41:23 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/15 16:57:48 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {
	try {
		Bureaucrat	Joe("Joe", 1);
		Bureaucrat	Bob("Bob", 26);
		std::string	target = "home";
		ShrubberyCreationForm	shrubb(target);
		PresidentialPardonForm	president("Criminal");
		RobotomyRequestForm		robot("Aji3");

		std::cout << std::endl;
		std::cout << "*************TRYING TO SIGN A FORM BY A TOO LOW GRADED BUREAUCRAT****************" << std::endl;
		Bob.signForm(president);
		
		std::cout << std::endl;
		std::cout << shrubb << std::endl;
		std::cout << "*****************TRYING TO EXECUTE A FORM WHEN IT IS NOT SIGNED******************" << std::endl;
		Joe.executeForm(shrubb);
		std::cout << std::endl;
		
		Joe.signForm(shrubb);
		std::cout << shrubb << std::endl;
		Joe.signForm(robot);
		Joe.signForm(president);
		
		std::cout << DEF "************TRYING TO EXECUTE A FORM BY A TOO LOW GRADED BUREAUCRAT**************" << std::endl;
		Bob.executeForm(president);
		std::cout << std::endl;
		
		
		Joe.executeForm(shrubb);
		std::cout << std::endl;
		Joe.executeForm(robot);
		std::cout << std::endl;
		Joe.executeForm(president);
		std::cout << std::endl;
		std::cout << "\t\tPRINT SHRUBBERY" << std::endl;
		std::ifstream fichier(target + "_shrubbery");
		if (!fichier) {
			std::cerr << "ERROR: cannot open file." << std::endl;
		return 1;
		}

		std::string ligne;
		while (std::getline(fichier, ligne)) {
			std::cout << ligne << std::endl;
		}
		fichier.close();
	}
	catch (std::exception& e) {
		std::cout << RED << e.what() << DEF << std::endl;
	}
	return (0);
}

