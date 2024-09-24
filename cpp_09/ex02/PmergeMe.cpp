#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& cpy) {*this = cpy;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vec = other._vec;
		_paires = other._paires;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char **av, int ac) {
	for (int i = 1; i < ac; i++) {
		parseArgs(av[i]);
		_vec.push_back(std::atoi(av[i]));
	}
	std::cout << "Before: ";
	for (size_t	i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl;
	sortVector();
}

void	PmergeMe::parseArgs(std::string av) {
	long int	tmp = std::strtol(av.c_str(), NULL, 0);
	if (tmp > INT_MAX)
		throw std::invalid_argument("Error: int max limit.");
	for (size_t i = 0; i < av.size(); i++) {
		if (!isdigit(av.at(i)))
			throw std::invalid_argument("Error: is not a positive number.");
	}
}

void	PmergeMe::sortVector() {
	std::clock_t	start = std::clock();
	createPairs();
	sortFusionInsertion();
	std::clock_t	end = std::clock();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector " << double(end - start) / CLOCKS_PER_SEC << " us" << std::endl;
}

void	PmergeMe::createPairs() {
	for (size_t	i = 0; i < _vec.size(); i += 2) {
		if (i + 1 < _vec.size()) {
			if (_vec[i] > _vec[i + 1])
				_paires.push_back(std::make_pair(_vec[i + 1], _vec[i]));
			else
				_paires.push_back(std::make_pair(_vec[i], _vec[i + 1]));
		} else {
			_paires.push_back(std::make_pair(_vec[i], -1));
		}
	}
}

std::vector<int>	generateJacobsthal(int n) {
	std::vector<int> jacobsthal;
	jacobsthal.push_back(1);
	if (n > 1) jacobsthal.push_back(3);

	for (int i = 2; i < n; ++i) {
		int	next = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
		if (next >= n) break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

void	PmergeMe::sortFusionInsertion() {
	std::vector<int>	first;
	std::vector<int>	seconds;

	for (size_t	i = 0; i < _paires.size(); i++) {
		first.push_back(_paires[i].first);
		if (_paires[i].second != -1)
			seconds.push_back(_paires[i].second);
	}

	FordJohnsonSort(seconds, seconds.begin(), seconds.end());
	std::vector<int> jacobsthal = generateJacobsthal(seconds.size());
	insertValue(jacobsthal, first, seconds);
}

void	PmergeMe::insertValue(std::vector<int> jacobsthal, std::vector<int> minValue, std::vector<int> maxValue) {
	for (size_t	j = 0; j < jacobsthal.size(); j++) {
		int	index = jacobsthal[j];
		if (index >= static_cast<int>(minValue.size()))
			index = minValue.size() - 1;
		int	prev_index = (j > 0) ? jacobsthal[j - 1] : -1;

		for (int	i = index; i > prev_index && i >= 0; i--) {
			std::vector<int>::iterator	pos = std::lower_bound(maxValue.begin(), maxValue.end(), minValue[i]);
			maxValue.insert(pos, minValue[i]);
		}
	}
	std::cout << "After: ";
	for (size_t	i = 0; i < maxValue.size(); i++)
		std::cout << maxValue[i] << " ";
	std::cout << std::endl;
}
