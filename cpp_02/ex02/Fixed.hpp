/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 10:21:48 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/20 08:38:37 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const & cpy);
	Fixed(int const intValue);
	Fixed(float const floatValue);
	~Fixed(void);

	Fixed&	operator=(Fixed const &obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(Fixed const &obj) const;
	bool	operator<(Fixed const &obj) const;
	bool	operator>=(Fixed const &obj) const;
	bool	operator<=(Fixed const &obj) const;
	bool	operator==(Fixed const &obj) const;
	bool	operator!=(Fixed const &obj) const;

	Fixed	operator+(const Fixed &obj) const;
	Fixed	operator-(const Fixed &obj) const;
	Fixed	operator*(const Fixed &obj) const;
	Fixed	operator/(const Fixed &obj) const;

	Fixed	operator++(void);
	Fixed	operator++(int);
	Fixed	operator--(void);
	Fixed	operator--(int);

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed&b);

private:

	int					_value;
	int const static	_bits = 8;

};

std::ostream& operator<<(std::ostream &o, const Fixed &obj);

#endif