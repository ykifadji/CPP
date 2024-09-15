#pragma once

#include <iostream>
#include <cctype>
#include <stack>
#include <stdexcept>

class RPN {
public:
	RPN(const std::string arg);
	~RPN();

private:
	std::stack<int>	_stack;

	RPN();
	RPN(const RPN& cpy);
	RPN&	operator=(const RPN& other);
};
