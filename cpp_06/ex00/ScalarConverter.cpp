/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 10:59:56 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/21 16:10:21 by ykifadji         ###   ########.fr       */
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
	for (size_t i = 0; i < literal.length(); i++) {
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

bool	ScalarConverter::isFloat(std::string &literal) {
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
		return true;

	size_t	length = literal.length();
	if (length < 2 || literal[length - 1] != 'f')
		return false;

	size_t	start = (literal[0] == '+' || literal[0] == '-') ? 1 : 0;
	bool	hasDot = false;
	for (size_t i = start; i < length - 1; ++i) {
		if (literal[i] == '.') {
			if (hasDot)
				return false;
			hasDot = true;
		} else if (!std::isdigit(literal[i]))
			return false;
	}
	return hasDot;
}

static int count_dot(const std::string &literal) {
	int dot_count = 0;
	for (size_t i = 0; i < literal.length(); ++i) {
		if (literal[i] == '.')
			++dot_count;
	}
	return dot_count;
}

bool ScalarConverter::isDouble(std::string &literal) {
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		return true;

	size_t start = 0;
	if (literal[0] == '+' || literal[0] == '-')
		start = 1;

	bool has_dot = false;
	for (size_t i = start; i < literal.length(); ++i) {
		if (literal[i] == '.') {
			if (has_dot)
				return false;
			has_dot = true;
		} else if (!std::isdigit(literal[i]))
			return false;
	}
	return has_dot && literal[literal.length() - 1] != '.' && count_dot(literal) == 1;
}

void	ScalarConverter::convert(std::string &literal) {
	if (isChar(literal) == true)
		convertChar(literal);
	else if (isInt(literal) == true)
		convertInt(literal);
	else if (isFloat(literal) == true)
		convertFloat(literal);
	else if (isDouble(literal) == true)
		convertDouble(literal);
	else
		throw (std::invalid_argument("ERROR: invalid argument."));
}

void	ScalarConverter::convertChar(std::string &literal) {
	_char = literal[0];
	_int = static_cast<int>(_char);
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	if (literal[0] < 32 || literal[0] > 126)
		throw(std::invalid_argument(RED"ERROR: invalid argument: non displayable character."));
	else
		std::cout << PURPLE"char: " DEF"'" BLUE << _char << "'" DEF << std::endl;
	std::cout << PURPLE"int: " DEF GREEN << _int << DEF << std::endl;
	std::cout << PURPLE"float: " DEF BLUE << std::fixed << std::setprecision(1) << _float << "f" DEF << std::endl;
	std::cout << PURPLE"double: " DEF GREEN << std::fixed << std::setprecision(1) << _double << DEF << std::endl;
}

void	ScalarConverter::convertInt(std::string &literal) {
	_int = std::atoi(literal.c_str());
	_char = static_cast<char>(_int);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
	if (_int < 0 || _int > 255)
		std::cout << PURPLE"char:" DEF RED " impossible" DEF << std::endl;
	else if (_int < 32 || _int > 126)
		std::cout << PURPLE"char:" DEF RED " non displayable" DEF << std::endl;
	else
		std::cout << PURPLE"char: " DEF"'" BLUE << _char << "'" DEF << std::endl;
	std::cout << PURPLE"int: " DEF GREEN << _int << DEF << std::endl;
	if (_float - _int == 0)
		std::cout << PURPLE"float: " DEF BLUE << std::fixed << std::setprecision(1) << _float << "f" DEF << std::endl;
	else
		std::cout << PURPLE"float: " DEF BLUE << _float << "f" DEF << std::endl;
	std::cout << PURPLE"double: " DEF GREEN << std::fixed << std::setprecision(1) << _double << DEF << std::endl;
}

static bool	handlePseudoLiterals(std::string &literal, int x) {
	std::string	literals[6] = {"nan", "-inf", "+inf", "nanf", "-inff", "+inff"};

	for (int i = 0; i < 6; i++) {
		if (literal == literals[i]) {
			std::cout << PURPLE"char:" DEF RED " impossible" DEF << std::endl;
			std::cout << PURPLE"int:" DEF RED " impossible" DEF << std::endl;
			if (x == 0) {
				std::cout << PURPLE"float: " DEF BLUE << literal + "f" DEF << std::endl;
				std::cout << PURPLE"double: " DEF GREEN << literal << DEF << std::endl;
			}
			else if (x == 1) {
				std::cout << PURPLE"float: " DEF BLUE << literal << DEF << std::endl;
				std::string	res = literals[i].substr(0, literals[i].length() - 1);
				std::cout << PURPLE"double: " DEF GREEN << res << DEF << std::endl;
			}
			return true;
		}
	}
	return false;
}

void	ScalarConverter::convertFloat(std::string &literal) {
	std::string	literals[3] = {"nanf", "-inff", "+inff"};
	if (handlePseudoLiterals(literal, 1))
		return ;
	_float = std::strtof(literal.c_str(), NULL);
	if (_float < -FLT_MAX || _float > +FLT_MAX)
		throw(std::invalid_argument(RED"ERROR: invalid argument: overflow."));
	_char = static_cast<char>(_float);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
	if (_float < 0 || _float > 255)
		std::cout << PURPLE"char:" DEF RED " impossible" DEF << std::endl;
	else if (_float < 32 || _float > 126)
		std::cout << PURPLE"char:" DEF RED " non displayable" DEF << std::endl;
	else
		std::cout << PURPLE"char: " DEF"'" BLUE << _char << "'" DEF << std::endl;
	std::cout << PURPLE"int: " DEF GREEN << _int << DEF << std::endl;
	if (_float - _int == 0)
		std::cout << PURPLE"float: " DEF BLUE << std::fixed << std::setprecision(1) << _float << "f" DEF << std::endl;
	else
		std::cout << PURPLE"float: " DEF BLUE << _float << "f" DEF << std::endl;
	if (_double - static_cast<int>(_double) == 0)
		std::cout << PURPLE"double: " DEF GREEN << std::fixed << std::setprecision(1) << _double << DEF << std::endl;
	else
	std::cout << PURPLE"double: " DEF GREEN << _double << DEF << std::endl;
}

void	ScalarConverter::convertDouble(std::string & literal) {
	if (handlePseudoLiterals(literal, 0))
		return;
	_double = std::strtod(literal.c_str(), NULL);
	if (_double < -DBL_MAX || _double > DBL_MAX)
		throw (std::invalid_argument("ERROR: Invalid argument: overflow !"));
	_char = static_cast<char>(_double);
	_int = static_cast<int>(_double);
	_float = static_cast<float>(_double);
	if (_float < 0 || _float > 255)
		std::cout << PURPLE"char:" DEF RED " impossible" DEF << std::endl;
	else if (_float < 32 || _float > 126)
		std::cout << PURPLE"char:" DEF RED " non displayable" DEF << std::endl;
	else
		std::cout << PURPLE"char: " DEF"'" BLUE << _char << "'" DEF << std::endl;
	std::cout << PURPLE"int: " DEF GREEN << _int << DEF << std::endl;
	if (_float - static_cast<int>(_float) == 0)
		std::cout << PURPLE"float: " DEF BLUE << std::fixed << std::setprecision(1) << _float << "f" DEF << std::endl;
	else
		std::cout << PURPLE"float: " DEF BLUE << _float << "f" DEF << std::endl;
	if (_double - _int == 0)
		std::cout << PURPLE"double: " DEF GREEN << std::fixed << std::setprecision(1) << _double << DEF << std::endl;
	else
	std::cout << PURPLE"double: " DEF GREEN << _double << DEF << std::endl;
}
