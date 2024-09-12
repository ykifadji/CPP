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

BitcoinExchange::BitcoinExchange(const char *file) {
	parseDatabase("data.csv");
	std::ifstream	ifs(file);
	if (!ifs.is_open())
		throw(NotOpenFile());
	std::string	line;
	bool	firstLine = true;
	while (std::getline(ifs, line)) {
		if (firstLine == true && line == "date | value") {
			firstLine = false;
			continue;
		}
		std::string	date, valueStr;
		std::stringstream	ss(line);

		std::getline(ss, date, '|');
		if (!date.empty() && date[date.size() - 1] == ' ')
			date = date.substr(0, date.size() - 1);
		std::getline(ss, valueStr);
		if (!valueStr.empty() && valueStr[0] == ' ')
			valueStr = valueStr.substr(1);
		float	value = std::atof(valueStr.c_str());

		if (!isValidDate(date)) {
			std::cerr << RED"Error: bad input => " << line << RES << std::endl;
			continue;
		}
		if (isPosNumber(valueStr)) {
			if (isNumberTooLarge(value)) {
				std::cerr << RED"Error: too large a number.";
				continue;
			}
			convertValueAtRate(date, value);
		} else
			std::cerr << RED"Error: not a positive number.";
	}
}

void	BitcoinExchange::parseDatabase(const char *file) {
	std::ifstream	ifs(file);
	if (!ifs.is_open())
		throw(NotOpenFile());
	std::string	line;
	bool	firstLine = true;
	while (std::getline(ifs, line)) {
		if (firstLine == true && line == "date,exchange_rate") {
			firstLine = false;
			continue;
		}
		std::string	date, rateStr;
		std::stringstream	ss(line);

		std::getline(ss, date, ',');
		std::getline(ss, rateStr);
		float	rate = std::atof(rateStr.c_str());

		if (!isValidDate(date))
			throw(DatabaseCorrupted());
		if (isPosNumber(rateStr)) {
			if (isNumberTooLarge(rate))
				throw(DatabaseCorrupted());
			_database[date] = rate;
		} else
			throw(DatabaseCorrupted());
	}
}

float	BitcoinExchange::searchDate(std::string date) {
	std::map<std::string, float>::iterator	it = _database.lower_bound(date);
	if (it == _database.end())
		--it;
	else if (it != _database.begin() && it->first != date)
		--it;
	return it->second;
}

bool	BitcoinExchange::isPosNumber(const std::string& str) {
	float	number;
	std::istringstream	iss(str);
	iss >> number;
	return !iss.fail() && number > 0;
}

bool	BitcoinExchange::isNumberTooLarge(float number) {return number > 2147483647;}

bool	BitcoinExchange::isValidDate(const std::string& date) {
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
	return valid;
}

const char	*BitcoinExchange::NotOpenFile::what() const throw() {
	return RED"Error: could not open file." RES;
}

const char	*BitcoinExchange::DatabaseCorrupted::what() const throw() {
	return RED"The database file is corrupted." RES;
}
