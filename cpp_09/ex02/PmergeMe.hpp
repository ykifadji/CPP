#pragma once

#include <iostream>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe& cpy);
	PmergeMe&	operator=(const PmergeMe& other);
	~PmergeMe();
};
