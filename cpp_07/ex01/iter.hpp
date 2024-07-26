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
void	iter(T *arr, size_t length, void (*f)(T &)) {
	for (size_t i = 0; i < length; i++)
		f(arr[i]);
}

template<typename T>
void	print(T& content) {std::cout << content << std::endl;}
