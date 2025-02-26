#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << RED"Error: could not open file." RES << std::endl;
		return 1;
	}

	try {
		BitcoinExchange	btc(av[1]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
