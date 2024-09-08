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

class BitcoinExchange {
public:
	void	parseFile(std::ifstream file);

private:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& cpy);
	BitcoinExchange&	operator=(const BitcoinExchange& other);
	~BitcoinExchange();
};
