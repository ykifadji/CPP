#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate () {
	srand(time(0));
	int	random = rand() % 3;
	Base	*p;

	if (random == 1)
		p = new A;
	else if (random == 2)
		p = new B;
	else
		p = new C;
	return p;
}

void	identify(Base* p) {
	if (dynamic_cast<A *>(p))
		std::cout << BLUE"The actual type of the object pointed to by p is A" DEF << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << BLUE"The actual type of the object pointed to by p is B" DEF << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << BLUE"The actual type of the object pointed to by p is C" DEF << std::endl;
	else
		std::cout << RED"Type is unknown" DEF << std::endl;
}

void	identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << GREEN"The actual type of the object referenced by p is A" DEF << std::endl;
	} catch (const std::exception& e) {
		try {
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << GREEN"The actual type of the object referenced by p is B" DEF << std::endl;
		} catch (const std::exception& e) {
			try {
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << GREEN"The actual type of the object referenced by p is C" DEF << std::endl;
			} catch (const std::exception& e) {
				std::cerr << RED DEF"Unknown type" DEF << std::endl;
			}
		}
	}
}

int	main() {
	Base	*test = generate();
	identify(test);
	identify(*test);
	delete test;
}
