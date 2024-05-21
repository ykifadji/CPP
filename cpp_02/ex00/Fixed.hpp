/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:00:14 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 12:23:13 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXED_CLASS_H

#include <iostream>

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const & cpy);
	Fixed& operator=(Fixed const & obj);
	~Fixed(void);


	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int					_value;
	int const static	_bits = 8;

};

#endif