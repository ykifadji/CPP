/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 08:29:45 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/23 12:08:15 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_H
# define CAT_CLASS_H

#include "Animal.hpp"

class Cat : public Animal {

public:

	Cat();
	Cat(const Cat& cpy);
	Cat&	operator=(const Cat& cpy);
	~Cat();

	void	makeSound() const;

};

#endif
