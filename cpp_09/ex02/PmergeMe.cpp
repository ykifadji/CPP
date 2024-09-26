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
	std::cout << PURPLE"Before: " RES;
	for (size_t	i = 0; i < _vec.size(); i++)
		std::cout << ORANGE << _vec[i] << " ";
	std::cout << RES << std::endl << std::endl;
	_resTimeVec = sortVector();
	_resTimeLst = sortList();
	printTime();
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

double	PmergeMe::sortVector() {
	std::clock_t	start = std::clock();
	createPairesVec();
	sortFusionInsertionVec();
	std::clock_t	end = std::clock();
	return double(end - start);
}

void	PmergeMe::createPairesVec() {
	for (size_t	i = 0; i < _vec.size(); i += 2) {
		if (i + 1 < _vec.size()) {
			if (_vec[i] > _vec[i + 1])
				_pairesVec.push_back(std::make_pair(_vec[i + 1], _vec[i]));
			else
				_pairesVec.push_back(std::make_pair(_vec[i], _vec[i + 1]));
		} else {
			_pairesVec.push_back(std::make_pair(_vec[i], -1));
		}
	}
}

void	PmergeMe::sortFusionInsertionVec() {
	std::vector<int>	minValueVec;
	std::vector<int>	maxValueVec;

	for (size_t	i = 0; i < _pairesVec.size(); i++) {
		minValueVec.push_back(_pairesVec[i].first);
		if (_pairesVec[i].second != -1)
			maxValueVec.push_back(_pairesVec[i].second);
	}

	FordJohnsonSortVec(maxValueVec, 0, maxValueVec.size() - 1);
	std::vector<int> jacobsthal = generateJacobsthalVec(maxValueVec.size());
	insertValueVec(jacobsthal, minValueVec, maxValueVec);
}

void	PmergeMe::FordJohnsonSortVec(std::vector<int> &vec, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		FordJohnsonSortVec(vec, left, mid);
		FordJohnsonSortVec(vec, mid + 1, right);
		merge(vec, left, mid, right);
	}
}

void PmergeMe::merge(std::vector<int>& vec, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> leftVec(n1);
	std::vector<int> rightVec(n2);

	for (int i = 0; i < n1; ++i)
		leftVec[i] = vec[left + i];
	for (int j = 0; j < n2; ++j)
		rightVec[j] = vec[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (leftVec[i] <= rightVec[j]) {
			vec[k++] = leftVec[i++];
		} else {
			vec[k++] = rightVec[j++];
		}
	}

	while (i < n1)
		vec[k++] = leftVec[i++];
	while (j < n2)
		vec[k++] = rightVec[j++];
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
	std::cout << PURPLE"After sort with Vector: " RES;
	for (size_t	i = 0; i < maxValue.size(); i++)
		std::cout << GREEN << maxValue[i] << " ";
	std::cout << RES << std::endl;
}

double	PmergeMe::sortList() {
	std::clock_t	start = std::clock();
	createPairesLst();
	sortFusionInsertionLst();
	std::clock_t	end = std::clock();
	return double(end - start);
}

void	PmergeMe::createPairesLst() {
	std::list<int>::iterator	it = _lst.begin();
	while (it != _lst.end()) {
		std::list<int>::iterator	nextIt = it;
		nextIt++;
		if (nextIt != _lst.end()) {
			if (*it > *nextIt)
				_pairesLst.push_back(std::make_pair(*nextIt, *it));
			else
				_pairesLst.push_back(std::make_pair(*it, *nextIt));
			++it;
			++it;
		} else {
			_pairesLst.push_back(std::make_pair(*it, -1));
			break;
		}
	}
}

void	PmergeMe::sortFusionInsertionLst() {
	std::list<int>		minValueLst;
	std::list<int>		maxValueLst;

	for (std::list<std::pair<int, int> >::iterator it = _pairesLst.begin(); it != _pairesLst.end(); ++it) {
		minValueLst.push_back(it->first);
		if (it->second != -1)
			maxValueLst.push_back(it->second);
	}

	FordJohnsonSortLst(maxValueLst, maxValueLst.begin(), maxValueLst.end());
	std::list<int> jacobsthal = generateJacobsthalLst(maxValueLst.size());
	insertValueLst(jacobsthal, minValueLst, maxValueLst);
}

void	PmergeMe::FordJohnsonSortLst(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right) {
	if (std::distance(left, right) > 1) {
		std::list<int>::iterator	mid = left;
		std::advance(mid, std::distance(left, right) / 2);
		FordJohnsonSortLst(list, left, mid);
		FordJohnsonSortLst(list, mid, right);
		std::inplace_merge(left, mid, right);
	}
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
	std::cout << std::endl << PURPLE"After sort with List: " RES;
	for (std::list<int>::iterator	it = maxValue.begin(); it != maxValue.end(); ++it)
		std::cout << GREEN << *it << " ";
	std::cout << RES << std::endl;
}

void	PmergeMe::printTime() {
	if (_resTimeVec < _resTimeLst) {
		std::cout << BLUE"Time to process a range of " << _vec.size() << " elements with std::vector : " RES GREEN << _resTimeVec / CLOCKS_PER_SEC << " us" RES << std::endl;
		std::cout << CYAN"Time to process a range of " << _vec.size() << " elements with std::list : " RES RED << _resTimeLst / CLOCKS_PER_SEC << " us" RES << std::endl;
	} else {
		std::cout << BLUE"Time to process a range of " << _vec.size() << " elements with std::vector : " RES RED << _resTimeVec / CLOCKS_PER_SEC << " us" RES << std::endl;
		std::cout << CYAN"Time to process a range of " << _vec.size() << " elements with std::list : " RES GREEN << _resTimeLst / CLOCKS_PER_SEC << " us" RES << std::endl;
	}
}
