#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>

# define RES "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define CYAN "\033[1m\033[96m"

class Span {
public:
	Span(const Span& cpy);
	Span&	operator=(const Span& other);
	~Span();

	Span(unsigned int N);

	unsigned int		getN() const;
	std::vector<int>	getVector() const;
	void				printStock() const;

	void			addNumber(int number);
	unsigned int	shortestSpan() const;
	unsigned int	longestSpan() const;

	template<typename I>
	void	addNumbers(I begin, I end) {
		unsigned int nb = 0;
		for (I	it = begin; it != end; ++it) {
			nb++;
			if (nb <= _N)
				_vector.push_back(*it);
			else
				throw(StockIsFull());
		}
	}

	class StockIsFull : public std::exception {
		virtual const char *what() const throw() {return RED"The storage is full." RES;}
	};

	class NotEnoughNumbers : public std::exception {
		virtual const char *what() const throw() {return RED"Insufficient numbers in storage." RES;}
	};

private:
	Span();
	unsigned int			_N;
	std::vector<int>		_vector;
};
