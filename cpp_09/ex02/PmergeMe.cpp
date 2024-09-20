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

void	PmergeMe::parseArgs(std::string av) {
	long int	tmp = std::strtol(av.c_str(), NULL, 0);
	if (tmp > INT_MAX)
		throw std::invalid_argument("Error: int max limit.");
	for (size_t i = 0; i < av.size(); i++) {
		if (!isdigit(av.at(i)))
			throw std::invalid_argument("Error: is not a positive number.");
	}
}

PmergeMe::PmergeMe(char **av, int ac) {
	size_t	size = ac;
	for (size_t i = 1; i < size; i++) {
		parseArgs(av[i]);
		_vec.push_back(std::atoi(av[i]));
	}
	createPairs();
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
	sortFusionInsertion();
}

//================TEST===================
std::vector<int> genererJacobsthal(int n) {
	std::vector<int> jacobsthal(n);
	jacobsthal[0] = 1;
	if (n > 1) jacobsthal[1] = 3;

	for (int i = 2; i < n; ++i) {
		jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
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

	
}

