#include "Span.hpp"

Span::Span() {}

Span::Span(const Span& cpy) {
	if (this != &cpy)
		*this = cpy;
}

Span::Span(unsigned int N): _N(N), _vector(0) {}

Span&	Span::operator=(const Span& other) {
	_N = other.getN();
	_vector = other.getVector();
	return *this;
}

Span::~Span() {}

unsigned int	Span::getN() const {return _N;}

std::vector<int>	Span::getVector() const {return _vector;}

void	Span::addNumber(int number) {
	if (_vector.size() < _N)
		_vector.push_back(number);
	else
		throw(StockIsFull());
}

unsigned int	Span::shortestSpan() const {
	if (_vector.size() < 2)
		throw(NotEnoughNumbers());
	std::vector<int>	cpy = _vector;
	std::sort(cpy.begin(), cpy.end());
	unsigned int	shortestDist = static_cast<unsigned int>(-1);

	for (std::vector<int>::const_iterator	it = cpy.begin(); it != cpy.end() -1; ++it) {
		unsigned int dist = static_cast<unsigned int>(*(it + 1) - *it);
		if (dist < shortestDist)
			shortestDist = dist;
	}
	return shortestDist;
}

unsigned int	Span::longestSpan() const {
	if (_vector.size() < 2)
		throw(NotEnoughNumbers());
	std::vector<int>	cpy = _vector;
	std::sort(cpy.begin(), cpy.end());
	return cpy.back() - cpy.front();
}

void	Span::printStock() const {
	for (std::vector<int>::const_iterator	it = _vector.begin(); it != _vector.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}
