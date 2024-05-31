/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:48:34 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/28 19:00:04 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

#include <iostream>
#include "AAnimal.hpp"

class Brain {

public:

	Brain();
	Brain(const Brain& cpy);
	Brain&	operator=(const Brain& cpy);
	~Brain();

private:

	static const int	_size = 100;
	std::string	_ideas[_size];

};

#endif
