#include "BitcoinExchange.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << RED"Error: could not open file." RES << std::endl;
		return 1;
	}

	std::ifstream	file(av[1]);
	if (!file.is_open()) {
		std::cerr << RED"Error: could not open file." RES << std::endl;
		return 1;
	}
	
}
