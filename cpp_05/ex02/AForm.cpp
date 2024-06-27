/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:09:15 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/27 10:26:39 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _gradeSign(0), _gradeExec(0) {
	std::cout << GREEN"AForm default constructor called." << std::endl;
}

AForm::AForm(const AForm& cpy): _name(cpy._name), _signed(cpy._signed), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec) {
	std::cout << GREEN"AForm copy constructor called." << std::endl;
}

AForm::AForm(const std::string& n, int gradeS, int gradeE): _name(n), _signed(false), _gradeSign(gradeS), _gradeExec(gradeE) {
	std::cout << GREEN"AForm parameter constructor called." << std::endl;
	if (gradeS < 1 || gradeE < 1)
		throw(GradeTooHighException());
	if (gradeS > 150 || gradeE > 150)
		throw(GradeTooLowException());
}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << RED"AForm destructor called." << std::endl;
}

const std::string	AForm::getName() const {return _name;}

bool	AForm::getSigned() const {return _signed;}

int	AForm::getGradeSign() const {return _gradeSign;}

int	AForm::getGradeExec() const {return _gradeExec;}

const char	*AForm::GradeTooHighException::what() const throw() {
	return RED"grade is too high." DEF;
}

const char	*AForm::GradeTooLowException::what() const throw() {
	return RED"grade is too low." DEF;
}

bool	AForm::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeSign) {
		_signed = true;
		return true;
	} else {
		throw(GradeTooLowException());
		return false;
	}
}

std::ostream& operator<<(std::ostream& o, const AForm& obj) {
	o << BLUE << "AForm " << obj.getName() << ", signed: " << (obj.getSigned() ? DEF GREEN"yes" DEF : DEF RED"no" DEF)
		<< BLUE", required grade to sign: " << obj.getGradeSign()
			<< ", required grade to execute: " << obj.getGradeExec() << "." DEF << std::endl;
	return o;
}
