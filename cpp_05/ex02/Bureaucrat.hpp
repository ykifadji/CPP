/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:02:25 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/13 19:35:11 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"

# define DEF "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define BROWN "\033[38;5;130m"

# define MAGBACK "\033[105m"

class AForm;

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

	void	signForm(AForm& form);
	void		executeForm(AForm const & form);

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
