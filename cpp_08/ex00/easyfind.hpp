#pragma once

# include <iostream>
# include <list>
# include <vector>
# include <iterator>
# include <algorithm>
# include <stdexcept>

# define RES "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define CYAN "\033[1m\033[96m"

template<typename T>
size_t	easyfind(T& container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::runtime_error(RED"Value not found." RES);
	return std::distance(container.begin(), it);
}
