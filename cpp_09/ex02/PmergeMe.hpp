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
#include <vector>

class PmergeMe {
public:
	PmergeMe(char **av, int ac);
	~PmergeMe();

	void	parse_args(std::string av);

private:
	std::vector<int>	_vec;
	PmergeMe();
	PmergeMe(const PmergeMe& cpy);
	PmergeMe&	operator=(const PmergeMe& other);
};
