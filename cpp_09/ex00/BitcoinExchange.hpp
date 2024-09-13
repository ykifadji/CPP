#pragma once

# define RES "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define CYAN "\033[1m\033[96m"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <cfloat>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange(const char *file);
	~BitcoinExchange();

	bool	isValidDate(const std::string& date);
	bool	isNumberTooLarge(double number);
	bool	isPosNumber(const std::string& str);

	void	parseDatabase(const char *file);
	float	searchDate(std::string date);
	void	convertValueAtRate(const std::string& date, float value);

private:
	std::map<std::string, float>	_database;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& cpy);
	BitcoinExchange&	operator=(const BitcoinExchange& other);
};
