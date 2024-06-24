/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:02:25 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/24 14:17:11 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << GREEN"Default constructor called." DEF << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): _name(cpy._name), _grade(cpy._grade) {
	std::cout << GREEN"Copy constructor called." DEF << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& n, int g): _name(n), _grade(g) {
	std::cout << GREEN"Parameter constructor called." DEF << std::endl;
	if (_grade < 1)
		throw(GradeTooHighException());
	else if (_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED"Destructor called." DEF << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}

void	Bureaucrat::incrGrade() {
	if (_grade - 1 < 1)
		throw(GradeTooHighException());
	else
		_grade -= 1;
}

void	Bureaucrat::decrGrade() {
	if (_grade + 1 > 150)
		throw(GradeTooLowException());
	else
		_grade += 1;
}

const std::string	Bureaucrat::getName() const {return _name;}

int	Bureaucrat::getGrade() const {return _grade;}

const char	*Bureaucrat::GradeTooHighException::what() const throw() {
	return RED"grade is too high." DEF;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw() {
	return RED"grade is too low." DEF;
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &obj) {
	o << BLUE << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." DEF << std::endl;
	return o;
}
