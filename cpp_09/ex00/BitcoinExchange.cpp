#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) {*this = cpy;}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		_database = other._database;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const char *file) {
	parseDatabase("data.csv");
	std::ifstream	ifs(file);
	if (!ifs.is_open())
		throw std::runtime_error(RED"Error: could not open file." RES);
	std::string	line;
	bool	firstLine = true;
	while (std::getline(ifs, line)) {
		if (firstLine == true && line == "date | value") {
			firstLine = false;
			continue;
		}
		std::string	date, valueStr;
		std::stringstream	ss(line);

		std::size_t	pos = line.find(" | ");
		if (pos != std::string::npos) {
			date = line.substr(0, pos);
			valueStr = line.substr(pos + 3);
		} else {
			std::cerr << RED"Error: bad input => " << line << RES << std::endl;
			continue;
		}
		float	value = std::strtof(valueStr.c_str(), NULL);

		if (!isValidDate(date)) {
			std::cerr << RED"Error: bad input => " << line << RES << std::endl;
			continue;
		}
		if (value >= 0) {
			if (value > 1000 ) {
				std::cerr << RED"Error: too large a number." RES << std::endl;
				continue;
			}
			convertValueAtRate(date, value);
		} else
			std::cerr << RED"Error: not a positive number." RES << std::endl;
	}
}

void	BitcoinExchange::convertValueAtRate(const std::string& date, float value) {
	float	rate = searchDate(date);
	if (rate < 0) {
		std::cerr << RED"Error: the date is too old." RES << std::endl;
		return;
	}
	double	res = value * rate;
	if (res > FLT_MAX)
		std::cerr << RED"Error: Float overflow from multiplication." RES << std::endl;
	else
		std::cout << PURPLE << date << RES ORANGE" => " RES PURPLE << value << RES ORANGE" = " RES GREEN << value * rate << RES << std::endl;
}

float	BitcoinExchange::searchDate(std::string date) {
	std::map<std::string, float>::iterator	it = _database.find(date);
	if (it != _database.end())
		return it->second;
	else {
		it = _database.lower_bound(date);
		if (it == _database.begin())
			return -1;
		--it;
	}
	return it->second;
}

void	BitcoinExchange::parseDatabase(const char *file) {
	std::ifstream	ifs(file);
	if (!ifs.is_open())
		throw std::runtime_error(RED"Error: could not open file." RES);
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
			throw std::runtime_error(RED"The database file is corrupted." RES);
		if (isPosNumber(rateStr)) {
			if (isNumberTooLarge(rate))
				throw std::runtime_error(RED"The database file is corrupted." RES);
			_database[date] = rate;
		} else
			throw std::runtime_error(RED"The database file is corrupted." RES);
	}
	if (_database.empty())
		throw std::runtime_error(RED"The database file is empty." RES);
}

bool	BitcoinExchange::isPosNumber(const std::string& str) {
	float	number;
	std::istringstream	iss(str);
	iss >> number;
	return !iss.fail() && number >= 0;
}

bool	BitcoinExchange::isNumberTooLarge(double number) {return number > 2147483647;}

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
