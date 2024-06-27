/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:02:25 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/27 08:38:02 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
	std::cout << GREEN"Bureaucrat default constructor called." DEF << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): _name(cpy._name), _grade(cpy._grade) {
	std::cout << GREEN"Bureaucrat copy constructor called." DEF << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& n, int g): _name(n), _grade(g) {
	std::cout << GREEN"Bureaucrat parameter constructor called." DEF << std::endl;
	if (_grade < 1)
		throw(GradeTooHighException());
	else if (_grade > 150)
		throw(GradeTooLowException());
}

Bureaucrat::~Bureaucrat() {
	std::cout << RED"Bureaucrat destructor called." DEF << std::endl;
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
	o << PURPLE << obj.getName() << ", bureaucrat grade " YELLOW << obj.getGrade() << DEF PURPLE"." DEF << std::endl;
	return o;
}

void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << YELLOW << _name << " signed " << form.getName() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}
