/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:19:56 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/28 18:52:16 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_CLASS_H
# define AANIMAL_CLASS_H

#include <iostream>

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"
# define YELLOW "\033[1m\033[38;5;226m"

class AAnimal {

public:

	AAnimal();
	AAnimal&	operator=(const AAnimal& cpy);
	AAnimal(const AAnimal& cpy);
	virtual ~AAnimal();

	AAnimal(std::string type);

	std::string	getType() const;

	virtual void	makeSound() const = 0;

protected:

	std::string	_type;
};

#endif