#include "Span.hpp"
#include <list>

int main() {
	Span sp(5);
	try {
		std::cout << GREEN"Shortest span with empty stock:" RES << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RES << std::endl;
	}

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << std::endl << GREEN"Print stock" RES << std::endl;
		sp.printStock();

		std::cout << GREEN"Test copy constructor:" RES << std::endl;
		Span sp_copy(sp);
		sp_copy.printStock();

		std::cout << GREEN"Test assignment operator:" RES << std::endl;
		Span sp_copy2(2);
		sp_copy2 = sp;
		sp_copy2.printStock();

		std::cout << CYAN"Calculate shortest span:" RES << std::endl;
		std::cout << sp.shortestSpan() << std::endl;

		std::cout << PURPLE"Calculate longest span:" RES << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		std::cout << GREEN"Add number to full stock:" RES << std::endl;
		sp.addNumber(2);
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RES << std::endl;
	}

	Span big_sp(100);
	std::cout << std::endl << GREEN"Add numbers with vector iterator:" RES << std::endl;
	try {
		std::vector<int> vec(10, 4);
		big_sp.addNumbers(vec.begin(), vec.end());
		big_sp.printStock();
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RES << std::endl;
	}

	std::cout << std::endl << GREEN"Add numbers with list iterator:" RES << std::endl;
	try {
		std::list<int> list;
		for (int i = 20; i <= 24; ++i) {
			list.push_back(i);
		}
		big_sp.addNumbers(list.begin(), list.end());
		big_sp.printStock();
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RES << std::endl;
	}

	std::cout << std::endl << CYAN"Calculate shortest span:" RES << std::endl;
	std::cout << big_sp.shortestSpan() << std::endl;

	std::cout << PURPLE"Calculate longest span" RES << std::endl;
	std::cout << big_sp.longestSpan() << std::endl;

	Span very_big_sp(12000);
	std::cout << std::endl << GREEN"Large range of iterators" RES << std::endl;
	try {
		std::vector<int> vec(10000, 5);
		very_big_sp.addNumbers(vec.begin(), vec.end());
		//very_big_sp.printStock();
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RES << std::endl;
	}
	return 0;
}
