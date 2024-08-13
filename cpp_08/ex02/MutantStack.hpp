#pragma once

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
#include <stdexcept>

# define RES "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define CYAN "\033[1m\033[96m"

template<typename T>
class MutantStack : public std::stack<T> {
public:
	MutantStack() {}
	MutantStack(const MutantStack& cpy) {*this = cpy;}
	~MutantStack() {}
	MutantStack&	operator=(const MutantStack& other) {
		std::stack<T>::operator=(other);
		return *this;
	}

	typedef typename std::stack<T>::container_type::iterator	iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

	iterator	begin() {return std::stack<T>::c.begin();}
	iterator	end() {return std::stack<T>::c.end();}
	const_iterator	begin() const {return std::stack<T>::c.begin();}
	const_iterator	end() const {return std::stack<T>::c.end();}

	void	printStack() const {
		for (const_iterator	it = begin(); it != end(); ++it)
			std::cout << *it << std::endl;
	}
};
