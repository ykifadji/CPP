/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:32:14 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/16 15:21:19 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
public:
	AForm(const AForm& cpy);
	AForm(const std::string& n, int gradeS, int gradeE);
	AForm&	operator=(const AForm& other);
	virtual ~AForm();

	const std::string	getName() const;
	bool				getSigned() const;
	int					getGradeSign() const;
	int					getGradeExec() const;

	bool				beSigned(Bureaucrat& bureaucrat);
	virtual void		execute(Bureaucrat const & executor) const = 0;

	class GradeTooHighException : public std::exception {
		virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char	*what() const throw();
	};

	class FormNotSignedException : public std::exception {
		virtual const char	*what() const throw();
	};

private:
	AForm();
	const std::string	_name;
	bool				_signed;
	const int			_gradeSign;
	const int			_gradeExec;
};

std::ostream& operator<<(std::ostream &o, const AForm &obj);
