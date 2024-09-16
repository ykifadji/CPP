#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& cpy) {*this = cpy;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other)
		*this = other;
	return *this;
}

PmergeMe::~PmergeMe() {}
