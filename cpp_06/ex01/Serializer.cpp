/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:16:11 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/23 16:23:38 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {};

Serializer::Serializer(const Serializer& cpy) {
	if (this != &cpy)
		*this = cpy;
}

Serializer&	Serializer::operator=(const Serializer& other) {
	(void)other;
	return *this;
}

Serializer::~Serializer() {};

uintptr_t	Serializer::serialize(Data* ptr) {
	uintptr_t	res = reinterpret_cast<uintptr_t>(ptr);
	return res;
}

Data*	Serializer::deserialize(uintptr_t raw) {
	Data	*res = reinterpret_cast<Data *>(raw);
	return res;
}
