#pragma once

#include <iostream>
#include <cctype>
#include <stack>
#include <stdexcept>

class RPN {
public:
	RPN(std::string arg);
	~RPN();

private:
	RPN();
	RPN(const RPN& cpy);
	RPN&	operator=(const RPN& other);
};
