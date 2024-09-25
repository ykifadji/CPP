#pragma once

# define RES "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define CYAN "\033[1m\033[96m"

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <climits>
#include <ctime>
#include <vector>
#include <list>

class PmergeMe {
public:
	PmergeMe(char **av, int ac);
	~PmergeMe();

	void	parseArgs(std::string av);
	void	sortFusionInsertionVec();
	void	sortFusionInsertionLst();
	void	insertValueVec(std::vector<int> jacobsthal, std::vector<int> minValue, std::vector<int> &maxValue);
	void	insertValueLst(std::list<int> jacobsthal, std::list<int> minValue, std::list<int> &maxValue);
	std::vector<int>	generateJacobsthalVec(int n);
	std::list<int>		generateJacobsthalLst(int n);

	void	sortVector();
	void	sortList();

private:
	std::vector<int>	_vec;
	std::vector<std::pair<int, int> >	_pairesVec;
	std::list<int>	_lst;
	std::list<std::pair<int, int> >	_pairesLst;

	PmergeMe();
	PmergeMe(const PmergeMe& cpy);
	PmergeMe&	operator=(const PmergeMe& other);
};

template<typename T, typename Iterator>
void	FordJohnsonSort(T &container, Iterator left, Iterator right) {
	if (std::distance(left, right) > 1) {
		Iterator	mid = left;
		std::advance(mid, std::distance(left, right) / 2);
		FordJohnsonSort(container, left, mid);
		FordJohnsonSort(container, mid, right);
		std::inplace_merge(left, mid, right);
	}
}

template<typename T, typename P>
void	createPairs(T &container, P &paires) {
	typename T::iterator	it = container.begin();
	while (it != container.end()) {
		typename T::iterator	nextIt = it;
		nextIt++;
		if (nextIt != container.end()) {
			if (*it > *nextIt)
				paires.push_back(std::make_pair(*nextIt, *it));
			else
				paires.push_back(std::make_pair(*it, *nextIt));
			++it;
			++it;
		} else {
			paires.push_back(std::make_pair(*it, -1));
			break;
		}
	}
}
