/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 08:48:34 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/24 16:31:43 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_H
# define BRAIN_CLASS_H

#include <iostream>
#include "Animal.hpp"

class Brain {

public:

	Brain();
	Brain(const Brain& cpy);
	Brain&	operator=(const Brain& cpy);
	~Brain();

private:

	std::string	_ideas[100];

};

#endif
