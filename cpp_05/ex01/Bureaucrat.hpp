/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:02:25 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/27 08:59:30 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"

# define DEF "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"

# define MAGBACK "\033[105m"

class Form;

class Bureaucrat {
public:
	Bureaucrat();
	Bureaucrat(const std::string& n, int g);
	Bureaucrat(const Bureaucrat& cpy);
	Bureaucrat&	operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string	getName() const;
	int			getGrade() const;

	void	incrGrade();
	void	decrGrade();

	void	signForm(Form& form);

	class GradeTooHighException : public std::exception {
		virtual const char	*what() const throw();
	};

	class GradeTooLowException : public std::exception {
		virtual const char	*what() const throw();
	};

private:
	std::string const	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream &o, const Bureaucrat &obj);
