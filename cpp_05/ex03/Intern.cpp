/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:51:37 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/16 15:23:50 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << GREEN"Intern default constructor called." DEF << std::endl;
}

Intern::Intern(const Intern& cpy) {
	std::cout << GREEN"Intern copy constructor called" DEF << std::endl;
	*this = cpy;
}

Intern::~Intern() {
	std::cout << RED"Intern destructor called" DEF << std::endl;
}

Intern&	Intern::operator=(const Intern& other) {
	if (this != &other)
		std::cout << GREEN"Intern assignement operator called" DEF << std::endl;
	return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target) {
	std::string	forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	fct_ptr	fct_ptrs[3] = {&Intern::createShrubberyCreationForm, &Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm};

	for (int i = 0; i < 3; i++) {
		if (forms[i] == name) {
			std::cout << CYAN"Intern creates " GREEN << name << DEF << std::endl;
			return (this->*fct_ptrs[i])(target);
		}
	}
	std::cerr << RED"Intern failed to create form because the name doesn't match any form" DEF << std::endl;
	return NULL;
}

AForm*	Intern::createRobotomyRequestForm(std::string target) {return new RobotomyRequestForm(target);}

AForm*	Intern::createPresidentialPardonForm(std::string target) {return new PresidentialPardonForm(target);}

AForm*	Intern::createShrubberyCreationForm(std::string target) {return new ShrubberyCreationForm(target);}
