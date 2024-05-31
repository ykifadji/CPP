/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:28:02 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/23 13:28:30 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_CLASS_H
# define WRONGANIMAL_CLASS_H

#include <iostream>

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"

class WrongAnimal {

public:

	WrongAnimal();
	WrongAnimal&	operator=(const WrongAnimal& cpy);
	WrongAnimal(const WrongAnimal& cpy);
	virtual ~WrongAnimal();

	WrongAnimal(std::string type);

	std::string	getType() const;

	void	makeSound() const;

protected:

	std::string	type;
};

#endif
