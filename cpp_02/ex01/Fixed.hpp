/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:13:11 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 12:23:32 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>
#include <cmath>

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"

class Fixed {

public:

	Fixed(void);
	Fixed(const Fixed &cpy);
	Fixed& operator=(const Fixed &obj);
	~Fixed(void);

	Fixed(int const intValue);
	Fixed(float const floatValue);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;

private:

	int					_value;
	int const static	_bits = 8;

};

std::ostream& operator<<(std::ostream &o, const Fixed &obj);

#endif