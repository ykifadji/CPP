#include "RPN.hpp"

int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	try {
		RPN	polish(av[1]);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
