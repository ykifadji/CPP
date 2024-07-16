/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:41:57 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/16 14:51:27 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern {
public:
	Intern();
	Intern(const Intern& cpy);
	Intern&	operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(std::string name, std::string target);
	AForm*	createRobotomyRequestForm(std::string target);
	AForm*	createPresidentialPardonForm(std::string target);
	AForm*	createShrubberyCreationForm(std::string target);

private:
	typedef AForm*	(Intern::*fct_ptr)(std::string);
};
