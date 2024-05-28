/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:39:57 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/28 18:58:26 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_H
# define DOG_CLASS_H

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{

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
