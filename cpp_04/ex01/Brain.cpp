/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 14:29:06 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/24 14:32:31 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << GREEN "Constructor Brain called" DEF << std::endl;
}

Brain::Brain(const Brain& cpy)

Brain::~Brain() {
	std::cout << RED "Destructor Brain called" << std::endl;
}
