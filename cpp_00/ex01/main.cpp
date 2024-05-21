/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:33:04 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 15:23:02 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	std::string	cmd;
	PhoneBook	phonebook;

	while (1) {
		std::cout << BOLD ORANGE "\tPlease enter command " DEF GREEN"ADD SEARCH" DEF BOLD ORANGE" or " DEF GREEN"EXIT" << std::endl << "\t\t";
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			return (1);
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.printDir();
		else if (cmd == "EXIT") {
			std::cout << CLEAR BOLD CYAN"\t~~~~~~~~~~~~~~~ GOODBYE ! ~~~~~~~~~~~~~~~" DEF << std::endl;
			break;
		}
		else
			std::cout << UP UP RED"\t             Invalid command.           " DEF << std::endl;
	}
	return (0);
}
