#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) {*this = cpy;}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		*this = other;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(char *file) {
	std::ifstream	ifs(file);
	if (!ifs.is_open())
		throw(NotOpenFile());
	
}

bool BitcoinExchange::is_valid_date(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!isdigit(date[i])) return false;
	}
	return true;
}

const char	*BitcoinExchange::NotOpenFile::what() const throw() {
	return RED"Error: could not open file." RES;
}

const char	*BitcoinExchange::NegativeNumber::what() const throw() {
	return RED"Error: noy a positive number." RES;
}

const char	*BitcoinExchange::TooLargeNumber::what() const throw() {
	return RED"Error: too large a number." RES;
}

const char	*BitcoinExchange::BadInput::what() const throw() {
	return RED"Error: bad input => "; // date a ajouter RES
}
