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
#include <climits>
#include <vector>

class PmergeMe {
public:
	PmergeMe(char **av, int ac);
	~PmergeMe();

	void	parseArgs(std::string av);
	void	createPairs();
	void	sortFusionInsertion();

private:
	std::vector<int>	_vec;
	std::vector<std::pair<int, int> >	_paires;

	PmergeMe();
	PmergeMe(const PmergeMe& cpy);
	PmergeMe&	operator=(const PmergeMe& other);
};
