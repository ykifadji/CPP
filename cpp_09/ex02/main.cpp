#include "PmergeMe.hpp"

int	main(int ac, char **av) {
	if (ac <= 2) {
		std::cerr << RED"Error: missing arguments" RES << std::endl;
		return 1;
	}

	try {
		PmergeMe	fjmi(av, ac);
	} catch (std::exception& e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	return 0;
}
