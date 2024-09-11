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
	std::string	line;
	while (std::getline(ifs, line)) {
		
	}
}

bool	BitcoinExchange::is_number_too_large(double number) {return number > 2147483647;}

bool	BitcoinExchange::is_valid_date(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int	year, month, day;
	if (sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		return false;

	if (year < 2009 || year > 2024)
		return false;
	if (month < 1 || month > 12)
		return false;

	bool	valid = false;
	switch (month) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			valid = (day >= 1 && day <= 31);
			break;
		case 4: case 6: case 9: case 11:
			valid = (day >= 1 && day <= 30);
			break;
		case 2:
			if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
				valid = (day >= 1 && day <= 29);
			else
				valid = (day >= 1 && day <= 28);
			break;
		default:
			valid = false;
			break;
	}
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
