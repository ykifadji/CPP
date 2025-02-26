#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& cpy) {*this = cpy;}

RPN&	RPN::operator=(const RPN& other) {
	_stack = other._stack;
	return *this;
}

RPN::~RPN() {}

RPN::RPN(const std::string arg) {
	if (arg.empty()) throw std::runtime_error("Error");

	for (std::string::size_type	i = 0; i < arg.size(); i++) {
		if (arg.at(i) == ' ') continue;

		if (isdigit(arg.at(i))) {
			if (i + 1 < arg.size() && arg.at(i + 1) != ' ')
				throw std::runtime_error("Error");
			else {
				int	nb = arg.at(i) - '0';
				_stack.push(nb);
			}
		}
		else if (arg.at(i) == '+' || arg.at(i) == '-' || arg.at(i) == '*' || arg.at(i) == '/') {
			if (i + 1 < arg.size() && arg.at(i + 1) != ' ')
				throw std::runtime_error("Error");
			else {
				if (_stack.size() < 2) throw std::runtime_error("Error");

				int	b = _stack.top(); _stack.pop();
				int	a = _stack.top(); _stack.pop();
				switch (arg.at(i)) {
					case '+':
						_stack.push(a + b); break;
					case '-':
						_stack.push(a - b); break;
					case '*':
						_stack.push(a * b); break;
					case '/':
						if (b == 0) throw std::runtime_error("Error");
						_stack.push(a / b); break;
					default:
						throw std::runtime_error("Error");
				}
			}
		}
		else
			throw std::runtime_error("Error");
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	else
		std::cout << _stack.top() << std::endl;
}
