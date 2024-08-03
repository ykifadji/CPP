#include "easyfind.hpp"

int	main() {
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	std::cout << ORANGE"\t\tTEST VECTOR" RES << std::endl;
	std::cout << CYAN"Test with good value:" RES << std::endl;
	try {
		size_t index = easyfind(vec, 3);
		std::cout << BLUE"Found in vector at index: " RES GREEN << index << RES << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << RED"Error in vector: " RES << e.what() << std::endl;
	}

	std::cout << CYAN"Test with bad value:" RES << std::endl;
	try {
		size_t index = easyfind(vec, 6);
		std::cout << BLUE"Found in vector at index: " RES GREEN << index << RES << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << RED"Error in vector: " RES << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);

	std::cout << std::endl << YELLOW"\t\tTEST LIST" RES << std::endl;
	std::cout << PURPLE"Test with good value:" RES << std::endl;
	try {
		size_t index = easyfind(lst, 20);
		std::cout << BLUE"Found in list at index: " RES GREEN << index << RES << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << RED"Error in list: " RES << e.what() << std::endl;
	}

	std::cout << PURPLE"Test with bad value:" RES << std::endl;
	try {
		size_t index = easyfind(lst, 60);
		std::cout << BLUE"Found in list at index: " RES GREEN << index << RES << std::endl;
	} catch (const std::runtime_error& e) {
		std::cerr << RED"Error in list: " RES << e.what() << std::endl;
	}
	return 0;
}
