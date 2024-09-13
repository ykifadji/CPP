#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& cpy) {
	if (this != &cpy)
		*this = cpy;
}

RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		*this = other;
	return *this;
}

RPN::~RPN() {}

RPN::RPN(std::string arg) {
	int	count_nb = 0;
	int	count_operator = 0;
	for (int	i = 0; i < arg.size(); i++) {
		if (isdigit(arg.at(i))) {
			if (arg.at(i + 1) != ' ')
				throw std::runtime_error("Error");
		}
			
	}
}
