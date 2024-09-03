/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 12:06:06 by ykifadji          #+#    #+#             */
/*   Updated: 2024/09/03 10:24:50 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cfloat>

# define DEF "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define CYAN "\033[96m"

class ScalarConverter {
public:
	static void	convert(std::string &literal);
	static void	convertChar(std::string &literal);
	static void	convertInt(std::string &literal);
	static void	convertFloat(std::string &literal);
	static void	convertDouble(std::string &literal);

	static bool	isChar(std::string &literal);
	static bool	isInt(std::string &literal);
	static bool	isFloat(std::string &literal);
	static bool	isDouble(std::string &literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& cpy);
	ScalarConverter&	operator=(const ScalarConverter& other);
	~ScalarConverter();

	static	char	_char;
	static	int		_int;
	static	float	_float;
	static	double	_double;
};
