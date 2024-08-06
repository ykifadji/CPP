#include "Span.hpp"

Span::Span() {}

Span::Span(const Span& cpy) {
	if (this != &cpy)
		*this = cpy;
}

Span::Span(unsigned int N): _N(N) {}

Span&	Span::operator=(const Span& other) {
	_N = other.getN();
	return *this;
}

Span::~Span() {}

unsigned int	Span::getN() const {return _N;}
