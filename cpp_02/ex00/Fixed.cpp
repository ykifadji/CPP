/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 14:53:40 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/18 08:08:53 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	std::cout << GREEN "Default constructor called" DEF << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & cpy) {
	std::cout << GREEN "Copy constructor called" DEF << std::endl;
	if (this != &cpy)
		*this = cpy;
}

Fixed& Fixed::operator=(Fixed const & obj) {
	std::cout << GREEN "Copy assignment operator called" DEF << std::endl;
	this->_value = obj._value;
	return *this;
}

Fixed::~Fixed(void) {
	std::cout << RED "Destructor called" DEF << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const {
	std::cout << ORANGE "getRawBits member function called" DEF << std::endl;
	return this->_value;
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
	return ;
}
