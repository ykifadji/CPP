/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:19:56 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/26 12:45:10 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_H
# define ANIMAL_CLASS_H

#include <iostream>

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"

class Animal {

public:

	Animal();
	Animal&	operator=(const Animal& cpy);
	Animal(const Animal& cpy);
	virtual ~Animal();

	Animal(std::string type);

	std::string	getType() const;

	virtual void	makeSound() const = 0;

protected:

	std::string	type;
};

#endif
