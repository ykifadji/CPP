#pragma once

#include <iostream>

class Span {
public:
	Span(const Span& cpy);
	Span&	operator=(const Span& other);
	~Span();

	Span(unsigned int N);

	unsigned int	getN() const;

private:
	Span();
	unsigned int	_N;
};
