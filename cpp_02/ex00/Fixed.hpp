/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:00:14 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/17 14:59:52 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_H
# define FIXE_CLASS_H

#include <iostream>

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"

class Fixed {

public:

	Fixed(void);
	Fixed(Fixed const & cpy);
	~Fixed(void);

	Fixed& operator=(Fixed const & obj);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:

	int					_value;
	int const static	_bits;

};

#endif