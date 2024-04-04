/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 09:33:04 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/02 10:36:50 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	std::string	cmd;
	PhoneBook	phonebook;

	while (1) {
		cout << BOLD ORANGE "\tPlease enter command " DEF GREEN"ADD SEARCH" DEF BOLD ORANGE" or " DEF GREEN"EXIT" << endl << "\t\t";
		std::getline(cin, cmd);
		if (cin.eof())
			return (1);
		if (cmd == "ADD")
			phonebook.addContact();
		else if (cmd == "SEARCH")
			phonebook.printDir();
		else if (cmd == "EXIT") {
			cout << CLEAR BOLD CYAN"\t~~~~~~~~~~~~~~~ GOODBYE ! ~~~~~~~~~~~~~~~" DEF << endl;
			break;
		}
		else
			cout << UP UP RED"\t             Invalid command.           " DEF << endl;
	}
	return (0);
}
