#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& cpy) {*this = cpy;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other)
		_vec = other._vec;
	return *this;
}

PmergeMe::~PmergeMe() {}

void	PmergeMe::parse_args(std::string av) {
	if (av.size() > 10 || (av.size() == 10 && av[9] > '7'))
		throw std::runtime_error("Error: int max limit.");
	for (size_t i = 0; i < av.size(); i++){
		if (!isdigit(av.at(i)))
			throw std::runtime_error("Error: is not a number.");
	}
}

PmergeMe::PmergeMe(char **av, int ac) {
	size_t	size = ac;
	for (size_t i = 1; i < size; i++) {
		parse_args(av[i]);
		_vec.push_back(std::atoi(av[i]));
	}
}

