#pragma once

#include <iostream>

# define DEF "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define CYAN "\033[1m\033[96m"

template<typename T>
void	swap(T & x, T & y) {
	T	tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T	max(T const & x, T & y) {return y >= x ? y : x;}

template<typename T>
T	min(T const & x, T & y) {return y <= x ? y : x;}