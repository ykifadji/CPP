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
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange(char *file);
	~BitcoinExchange();

	bool	is_valid_date(const std::string& date);
	bool	is_number_too_large(double number);
	bool	is_pos_number(const std::string& str, double& number);

	class NotOpenFile : public std::exception {
		virtual const char	*what() const throw();
	};

	class NegativeNumber : public std::exception {
		virtual const char	*what() const throw();
	};

	class BadInput : public std::exception {
		virtual const char	*what() const throw();
	};

	class TooLargeNumber : public std::exception {
		virtual const char	*what() const throw();
	};

private:
	std::map<std::string, int>	_database;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& cpy);
	BitcoinExchange&	operator=(const BitcoinExchange& other);
};
