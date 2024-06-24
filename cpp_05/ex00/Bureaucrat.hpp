/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 09:42:06 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/24 11:19:23 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"

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
