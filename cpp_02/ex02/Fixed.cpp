/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:22:01 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/20 17:20:27 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0) {
	return ;
}

Fixed::Fixed(Fixed const &cpy) {
	if (this != &cpy)
		*this = cpy;
	return ;
}

Fixed::Fixed(int const intValue) {
	this->_value = intValue << this->_bits;
	return ;
}

Fixed::Fixed(float const floatValue) {
	this->_value = roundf(floatValue * (1 << this->_bits));
	return ;
}

Fixed& Fixed::operator=(Fixed const &obj) {
	this->_value = obj._value;
	return *this;
}

Fixed::~Fixed(void) {
	return ;
}

int	Fixed::getRawBits(void) const {
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

bool Fixed::operator>(const Fixed &obj) const {
	return this->_value > obj._value;
}

bool Fixed::operator<(const Fixed &obj) const {
	return this->_value < obj._value;
}

bool Fixed::operator>=(const Fixed &obj) const {
	return this->_value >= obj._value;
}

bool Fixed::operator<=(const Fixed &obj) const {
	return this->_value <= obj._value;
}

bool Fixed::operator==(const Fixed &obj) const {
	return this->_value == obj._value;
}

bool Fixed::operator!=(const Fixed &obj) const {
	return this->_value != obj._value;
}

Fixed	Fixed::operator+(const Fixed &obj) const {
	Fixed	res;
	res._value = this->_value + obj._value;
	return res;
}

Fixed	Fixed::operator-(const Fixed &obj) const {
	Fixed	res;
	res._value = this->_value - obj._value;
	return res;
}

Fixed	Fixed::operator*(const Fixed &obj) const {
	Fixed	res;
	res._value = (this->_value * obj._value) >> this->_bits;
	return res;
}

Fixed	Fixed::operator/(const Fixed &obj) const {
	Fixed	res;
	res._value = (this->_value / obj._value) << this->_bits;
	return res;
}

Fixed	Fixed::operator++(void) {
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	++(*this);
	return tmp;
}

Fixed	Fixed::operator--(void) {
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	--(*this);
	return tmp;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}
