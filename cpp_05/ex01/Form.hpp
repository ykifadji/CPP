/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:32:14 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/26 17:07:20 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"

class Bureaucrat;

class Form {
public:
	Form();
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
	const std::string	_name;
	bool				_signed;
	int					_gradeSign;
	int					_gradeExec;
};

std::ostream& operator<<(std::ostream &o, const Form &obj);
