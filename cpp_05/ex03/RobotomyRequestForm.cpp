/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:32:03 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/16 14:59:05 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), _target("unknown") {
	std::cout << GREEN"RobotomyRequestForm default constructor called" DEF << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request", 72, 45), _target(target) {
	std::cout << GREEN"RobotomyRequestForm parameter constructor called" DEF << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy) : AForm(cpy), _target(cpy._target) {
	std::cout << GREEN"RobotomyRequestForm copy constructor called" DEF << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << RED"RobotomyRequestForm destructor called" DEF << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other)
		_target = other._target;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat & executor) const {
	if (getSigned() == false)
		throw(FormNotSignedException());
	else if (executor.getGrade() > getGradeExec())
		throw(GradeTooLowException());
	else {
		std::cout << BROWN"Brrrrrrrrrr!!" DEF << std::endl;
		srand(time(0));
		int	success = rand() % 100;
		if (success < 50)
			std::cout << PURPLE << _target << " has been robotomized successfully !" DEF << std::endl;
		else
			std::cout << ORANGE"Robotomy of " << _target << " failed !" DEF << std::endl;
	}
}
