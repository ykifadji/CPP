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
	void	printTime();

	std::vector<int>	generateJacobsthalVec(int n);
	std::list<int>		generateJacobsthalLst(int n);

	void	createPairesLst();
	void	createPairesVec();

	void	sortFusionInsertionVec();
	void	sortFusionInsertionLst();

	void	FordJohnsonSortLst(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right);
	void	FordJohnsonSortVec(std::vector<int> &vec, int left, int right);
	void	merge(std::vector<int>& vec, int left, int mid, int right);

	void	insertValueVec(std::vector<int> jacobsthal, std::vector<int> minValue, std::vector<int> &maxValue);
	void	insertValueLst(std::list<int> jacobsthal, std::list<int> minValue, std::list<int> &maxValue);

	double	sortVector();
	double	sortList();

private:
	std::vector<int>					_vec;
	std::vector<std::pair<int, int> >	_pairesVec;
	std::list<int>						_lst;
	std::list<std::pair<int, int> >		_pairesLst;
	double								_resTimeVec;
	double								_resTimeLst;

	PmergeMe();
	PmergeMe(const PmergeMe& cpy);
	PmergeMe&	operator=(const PmergeMe& other);
};
