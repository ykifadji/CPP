/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:09:15 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/26 17:22:45 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() {
	std::cout << GREEN"Form default constructor called." << std::endl;
}

Form::Form(const Form& cpy): _name(cpy._name), _signed(cpy._signed), _gradeSign(cpy._gradeSign), _gradeExec(cpy._gradeExec) {
	std::cout << GREEN"Form copy constructor called." << std::endl;
}

Form::Form(const std::string& n, int gradeS, int gradeE): _name(n), _signed(false), _gradeSign(gradeS), _gradeExec(gradeE) {
	std::cout << GREEN"Form parameter constructor called." << std::endl;
	if (gradeS < 1 || gradeE < 1)
		throw(GradeTooHighException());
	if (gradeS > 150 || gradeE > 150)
		throw(GradeTooLowException());
}

Form&	Form::operator=(const Form& other) {
	if (this != &other) {
		_signed = other._signed;
		_gradeSign = other._gradeSign;
		_gradeExec = other._gradeExec;
	}
	return *this;
}

Form::~Form() {
	std::cout << RED"Form destructor called." << std::endl;
}

const std::string	Form::getName() const {return _name;}

bool	Form::getSigned() const {return _signed;}

int	Form::getGradeSign() const {return _gradeSign;}

int	Form::getGradeExec() const {return _gradeExec;}

const char	*Form::GradeTooHighException::what() const throw() {
	return RED"grade is too high." DEF;
}

const char	*Form::GradeTooLowException::what() const throw() {
	return RED"grade is too low." DEF;
}

bool	Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() <= _gradeSign) {
		_signed = true;
		return true;
	} else {
		throw(GradeTooLowException());
		return false;
	}
}
