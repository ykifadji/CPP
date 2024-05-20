/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:21:07 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/18 10:25:29 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	std::cout << GREEN "Default constructor called" DEF << std::endl;
	return ;
}

Fixed::Fixed(const Fixed &cpy) {
	std::cout << GREEN "Copy constructor called" DEF << std::endl;
	if (this != &cpy)
		*this = cpy;
	return ;
}

Fixed::Fixed(int const intValue) {
	this->_value = intValue << this->_bits;
	std::cout << GREEN "Int constructor called" DEF << std::endl;
	return ;
}

Fixed::Fixed(float const floatValue) {
	this->_value = roundf(floatValue * (1 << this->_bits));
	std::cout << GREEN "Float constructor called" DEF << std::endl;
	return ;
}

Fixed& Fixed::operator=(const Fixed &obj) {
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

float	Fixed::toFloat(void) const {
	return (float)this->_value / (1 << this->_bits);
}

int	Fixed::toInt(void) const {
	return this->_value >> this->_bits;
}

std::ostream& operator<<(std::ostream &o, const Fixed &obj) {
	o << obj.toFloat();
	return o;
}
