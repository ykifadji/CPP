/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:32:14 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/27 10:27:04 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form(const Form& cpy);
	Form(const std::string& n, int gradeS, int gradeE);
	Form&	operator=(const Form& other);
	~Form();

	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;

	bool				beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception {
		virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char	*what() const throw();
	};

private:
	Form();
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;
};

std::ostream& operator<<(std::ostream &o, const Form &obj);
