#pragma once

#include <iostream>
#include <cstdlib>

# define RES "\033[0m"
# define RED "\033[1m\033[91m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"
# define PURPLE "\033[1m\033[38;5;147m"
# define CYAN "\033[1m\033[96m"

template<typename T>
class Array {
public:
	Array(): _array(new T[0]), _size(0) {}
	Array(const Array<T> &cpy) {*this = cpy;}
	~Array() {delete [] _array;}

	Array(unsigned int n): _array(new T[n]), _size(n) {}
	Array<T>&	operator=(const Array<T> &other) {
		_array = new T[other._size];
		_size = other._size;
		for (size_t i = 0; i < _size; i++)
			_array[i] = other._array[i];
		return *this;}

	T&	operator[](int index) const {
		if (index < 0 || static_cast<unsigned int>(index) >= _size)
			throw(OutofBoundsException());
		return _array[index];}

	unsigned int	size() const {return _size;}

	class OutofBoundsException : public std::exception {
		public:
			virtual const char	*what() const throw() {return RED"Index is out of bounds." RES;}
	};

private:
	T				*_array;
	unsigned int	_size;
};
