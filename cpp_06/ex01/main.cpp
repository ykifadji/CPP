/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:25:49 by ykifadji          #+#    #+#             */
/*   Updated: 2024/07/24 12:32:05 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(void) {
	Data		*data = new Data;
	uintptr_t	serialize_res;
	Data		*deserialize_res;

	data->firstName = "Bill";
	data->lastName = "Johnson";
	data->age = 33;
	try {
		serialize_res = Serializer::serialize(data);
		deserialize_res = Serializer::deserialize(serialize_res);

		std::cout << ORANGE"\t\tPRINT POINTER ADDRESSES" DEF << std::endl;
		std::cout << PURPLE"Original pointer = " DEF GREEN << data << DEF << std::endl;
		std::cout << PURPLE"Result pointer = " DEF GREEN << deserialize_res << DEF << std::endl << std::endl;

		std::cout << ORANGE << "\tPRINT VARIABLES FROM POINTER RETURNED BY DESERIALIZE FUNCTION" DEF << std::endl;
		std::cout << PURPLE"Firstname = " DEF GREEN << deserialize_res->firstName << DEF << std::endl;
		std::cout << PURPLE"Lastname = " DEF GREEN << deserialize_res->lastName << DEF << std::endl;
		std::cout << PURPLE"Age = " DEF GREEN << deserialize_res->age << DEF << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << DEF << std::endl;
	}
	delete data;
	return 0;
}