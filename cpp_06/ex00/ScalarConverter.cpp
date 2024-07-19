/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:59:56 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/19 12:39:51 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char	ScalarConverter::_char = 0;
int		ScalarConverter::_int = 0;
float	ScalarConverter::_float = 0;
double	ScalarConverter::_double = 0;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& cpy) {
	if (this != &cpy)
		*this = cpy;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

bool	ScalarConverter::isChar(std::string &literal) {
	if (literal.length() == 1 && (literal[0] < '0' || literal[0] > '9'))
		return true;
	return false;
}

bool	ScalarConverter::isInt(std::string &literal) {
	for (int i = 0; i < literal.length(); i++) {
		if (i == 0 && (literal[i] == '+' || literal[i] == '-'))
			continue;
		else if (!std::isdigit(literal[i]))
			return false;
	}
	long int	res = std::strtol(literal.c_str(), NULL, 10);
	if (res < INT_MIN || res > INT_MAX)
		throw(std::invalid_argument("ERROR: Invalid argument: overflow."));
	return true;
}

void	ScalarConverter::convertChar(std::string &literal) {
	_char = literal[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	if (literal[0] < 32 || literal[0] > 126)
		throw(std::invalid_argument(RED"ERROR: invalid argument: no displayable character."));
	else
		std::cout << CYAN"char: " DEF"'" YELLOW << _char << "'" DEF << std::endl;
	std::cout << PURPLE"int: " DEF ORANGE << _int << DEF << std::endl;
	std::cout << CYAN"float: " DEF YELLOW << std::fixed << std::setprecision(1) << _float << "f" DEF << std::endl;
	std::cout << PURPLE"double: " DEF ORANGE << std::fixed << std::setprecision(1) << _double << DEF << std::endl;
}

void	ScalarConverter::convert(std::string &literal) {
	if (isChar(literal) == true)
		convertChar(literal);
}