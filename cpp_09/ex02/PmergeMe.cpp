#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& cpy) {*this = cpy;}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		*this = other;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(char **av, int ac) {
	for (int i = 1; i < ac; i++) {
		parseArgs(av[i]);
		_vec.push_back(std::atoi(av[i]));
		_lst.push_back(std::atoi(av[i]));
	}
	std::cout << "Before: ";
	for (size_t	i = 0; i < _vec.size(); i++)
		std::cout << _vec[i] << " ";
	std::cout << std::endl << std::endl;
	sortVector();
	sortList();
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
	createPairs(_vec, _pairesVec);
	sortFusionInsertionVec();
	std::clock_t	end = std::clock();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::vector " << double(end - start) / CLOCKS_PER_SEC << " us" << std::endl;
}

void	PmergeMe::sortFusionInsertionVec() {
	std::vector<int>	minValueVec;
	std::vector<int>	maxValueVec;

	for (size_t	i = 0; i < _pairesVec.size(); i++) {
		minValueVec.push_back(_pairesVec[i].first);
		if (_pairesVec[i].second != -1)
			maxValueVec.push_back(_pairesVec[i].second);
	}

	FordJohnsonSort(maxValueVec, maxValueVec.begin(), maxValueVec.end());
	std::vector<int> jacobsthal = generateJacobsthalVec(maxValueVec.size());
	insertValueVec(jacobsthal, minValueVec, maxValueVec);
}

std::vector<int>	PmergeMe::generateJacobsthalVec(int n) {
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

void	PmergeMe::insertValueVec(std::vector<int> jacobsthal, std::vector<int> minValue, std::vector<int> &maxValue) {
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
	for (size_t i = 0; i < minValue.size(); ++i) {
		if (std::find(maxValue.begin(), maxValue.end(), minValue[i]) == maxValue.end()) {
			std::vector<int>::iterator pos = std::lower_bound(maxValue.begin(), maxValue.end(), minValue[i]);
			maxValue.insert(pos, minValue[i]);
		}
	}
	std::cout << "After Vector: ";
	for (size_t	i = 0; i < maxValue.size(); i++)
		std::cout << maxValue[i] << " ";
	std::cout << std::endl;
}

void	PmergeMe::sortList() {
	std::clock_t	start = std::clock();
	createPairs(_lst, _pairesLst);
	sortFusionInsertionLst();
	std::clock_t	end = std::clock();
	std::cout << "Time to process a range of " << _vec.size() << " elements with std::list " << double(end - start) / CLOCKS_PER_SEC << " us" << std::endl;
}

void	PmergeMe::sortFusionInsertionLst() {
	std::list<int>		minValueLst;
	std::list<int>		maxValueLst;

	for (std::list<std::pair<int, int> >::iterator it = _pairesLst.begin(); it != _pairesLst.end(); ++it) {
		minValueLst.push_back(it->first);
		if (it->second != -1)
			maxValueLst.push_back(it->second);
	}

	FordJohnsonSort(maxValueLst, maxValueLst.begin(), maxValueLst.end());
	std::list<int> jacobsthal = generateJacobsthalLst(maxValueLst.size());
	insertValueLst(jacobsthal, minValueLst, maxValueLst);
}

std::list<int>	PmergeMe::generateJacobsthalLst(int n) {
	std::list<int>	jacobsthal;
	jacobsthal.push_back(1);
	if (n > 1) jacobsthal.push_back(3);

	for (int	i = 2; i < n;++i) {
		std::list<int>::iterator	it = jacobsthal.end();
		int next = *(--it) + 2 * *(--it);
		if (next >= n) break;
		jacobsthal.push_back(next);
	}
	return jacobsthal;
}

void	PmergeMe::insertValueLst(std::list<int> jacobsthal, std::list<int> minValue, std::list<int> &maxValue) {
	std::list<int>::iterator it = jacobsthal.begin();
	for (size_t j = 0; j < jacobsthal.size(); ++j, ++it) {
		int index = *it;
		if (index >= static_cast<int>(minValue.size()))
			index = minValue.size() - 1;
		int prev_index = -1;
		if (j > 0) {
			std::list<int>::iterator prevIt = it;
			--prevIt;
			prev_index = *prevIt;
		}

		std::list<int>::iterator minIt = minValue.begin();
		std::advance(minIt, index);

		for (int i = index; i > prev_index && i >= 0; --i) {
			std::list<int>::iterator pos = std::lower_bound(maxValue.begin(), maxValue.end(), *minIt);
			if (std::find(maxValue.begin(), maxValue.end(), *minIt) == maxValue.end())
				maxValue.insert(pos, *minIt);
			if (i > 0) --minIt;
		}
	}

	for (std::list<int>::iterator	minIt = minValue.begin(); minIt != minValue.end(); ++minIt) {
		if (std::find(maxValue.begin(), maxValue.end(), *minIt) == maxValue.end()) {
			std::list<int>::iterator	pos = std::lower_bound(maxValue.begin(), maxValue.end(), *minIt);
			maxValue.insert(pos, *minIt);
		}
	}
	std::cout << std::endl << "After List: ";
	for (std::list<int>::iterator	it = maxValue.begin(); it != maxValue.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
