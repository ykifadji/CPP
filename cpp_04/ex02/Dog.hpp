/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:39:57 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/25 16:25:32 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_H
# define DOG_CLASS_H

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal{

public:

	Dog();
	Dog(const Dog& cpy);
	Dog&	operator=(const Dog& cpy);
	~Dog();

	void	makeSound() const;

private:

	Brain*	_brain;
};

#endif
