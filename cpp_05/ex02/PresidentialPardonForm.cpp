/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:46:49 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/15 16:53:19 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 25, 5), _target("unknown") {
	std::cout << GREEN"PresidentialPardonForm default constructor called" DEF << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5), _target(target) {
	std::cout << GREEN"PresidentialPardonForm parameter constructor called" DEF << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & cpy) : AForm(cpy), _target(cpy._target) {
	std::cout << GREEN"PresidentialPardonForm copy constructor called" DEF << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << RED"PresidentialPardonForm destructor called" DEF << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const & other) {
	if (this != &other)
		_target = other._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (getSigned() == false)
		throw(FormNotSignedException());
	else if (executor.getGrade() > getGradeExec())
		throw(GradeTooLowException());
	else
		std::cout << BLUE << _target << " has been pardoned by Zaphod Beeblebrox" DEF << std::endl;
}
