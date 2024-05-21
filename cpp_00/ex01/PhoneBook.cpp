/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:57:37 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 15:22:27 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	PhoneBook::i = 0;

PhoneBook::PhoneBook(void) {

	std::cout << BOLD GREEN "Constructor PhoneBook called" DEF << std::endl;
	return ;
}

PhoneBook::~PhoneBook(void) {

	std::cout << BOLD RED "Destructor PhoneBook called" DEF << std::endl;
	return ;
}

void	PhoneBook::updatePhoneBook(void) {

	if (i > 7) {
		for (int k = 0; k < i - 1; k++)
			contact[k] = contact[k + 1];
		i--;
	}
	return ;
}

int	PhoneBook::parsNumber(std::string input) {

	for (size_t j = 0; j < input.size(); j++)
		if (!std::isdigit(input[j]) && input[j] != ' ')
			return 1;
	return 0;
}

void	PhoneBook::addContact(void) {

	if (i > 7)
		updatePhoneBook();
	while (1) {
		std::cout << UNDERLINE BOLD BLUE "\tPlease enter first name :" DEF BOLD GREEN << std::endl << "\t\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (!input.empty()) {
			contact[i].setFirstname(input);
			break;
		} else
			std::cout << UP UP RED"\t      Invalid input      " DEF << std::endl;
	}
	while (1) {
		std::cout << UNDERLINE BOLD BLUE "\tPlease enter last name :" DEF BOLD GREEN << std::endl << "\t\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (!input.empty()) {
			contact[i].setLastname(input);
			break;
		} else
			std::cout << UP UP RED"\t      Invalid input      " DEF << std::endl;
	}
	while (1) {
		std::cout << UNDERLINE BOLD BLUE "\tPlease enter nick name :" DEF BOLD GREEN << std::endl << "\t\t";
		if (std::cin.eof())
			exit(1);
		std::getline(std::cin, input);
		if (!input.empty()) {
			contact[i].setNickname(input);
			break;
		} else
			std::cout << UP UP RED"\t      Invalid input      " DEF << std::endl;
	}
	while (1) {
		std::cout << UNDERLINE BOLD BLUE "\tPlease enter phone number :" DEF BOLD GREEN << std::endl << "\t\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (!input.empty()) {
			if (parsNumber(input)) {
				std::cout << UP UP RED"\t       Invalid input       " DEF << std::endl;
				continue;
			}
			contact[i].setPhonenumber(input);
			break;
		} else
			std::cout << UP UP RED"\t       Invalid input       " DEF << std::endl;
	}
	while (1) {
		std::cout << UNDERLINE BOLD BLUE "\tPlease enter his darkest secret :" DEF BOLD GREEN << std::endl << "\t\t";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (!input.empty()) {
			contact[i].setDarkestsecret(input);
			break;
		} else
			std::cout << UP UP RED"\t          Invalid input          " DEF << std::endl;
	}
	if (i < 8)
		i++;
	std::cout << BOLD PINK "\tContact was successfully added !" DEF << std::endl;
	return ;
}

std::string	PhoneBook::updateName(std::string str) {
	std::string	newstr;

	if (str.size() <= 10)
		return str;
	newstr.resize(10);
	for (int j = 0; j < 9; j++)
		newstr[j] = str[j];
	newstr[9] = '.';
	return newstr;
}

void	PhoneBook::printDir(void) {
	std::string	underscore(45, '~');

	if (i == 0) {
		std::cout << UNDERLINE RED"\t\tThe contact directory is empty." DEF << std::endl;
		return ;
	} else {
		std::cout << CLEAR"\t" << PIPE UNDERLINE BOLD GREEN"   Index  " PIPE;
		std::cout << UNDERLINE BOLD GREEN"First name" PIPE;
		std::cout << UNDERLINE BOLD GREEN"Last name " PIPE;
		std::cout << UNDERLINE BOLD GREEN" Nickname " PIPE << std::endl;
	} for (int j = 0; j < i; j++) {
			std::cout << '\t' << PIPE << PURPLE << std::right << std::setw(10) << j + 1 << PIPE;
			std::cout << BLUE << std::right << std::setw(10) << updateName(contact[j].getFirstname()) << PIPE;
			std::cout << BLUE << std::right << std::setw(10) << updateName(contact[j].getLastname()) << PIPE;
			std::cout << BLUE << std::right << std::setw(10) << updateName(contact[j].getNickname())<< PIPE << std::endl;
			std::cout << '\t' << ORANGE << underscore << DEF << std::endl;
	}
	parsIndex();
	return ;
}

void	PhoneBook::displayContact(int index) {

	std::cout << CLEAR UNDERLINE BOLD BLUE"His First name:" DEF << "\t\t" << CYAN << contact[index].getFirstname() << std::endl;
	std::cout << UNDERLINE BOLD BLUE"His Last name:" DEF << "\t\t" << CYAN << contact[index].getLastname() << std::endl;
	std::cout << UNDERLINE BOLD BLUE"His Nick name:" DEF << "\t\t" << CYAN << contact[index].getNickname() << std::endl;
	std::cout << UNDERLINE BOLD BLUE"His Phone number:" DEF << '\t' << CYAN << contact[index].getPhonenumber() << std::endl;
	std::cout << UNDERLINE BOLD BLUE"His Darkest secret:" DEF << '\t' << CYAN << contact[index].getDarkestsecret() << std::endl;
	return ;
}

void	PhoneBook::parsIndex(void) {
	std::string	cmd;
	int			index;

	while (1) {
		std::cout << GREEN BOLD"Please enter an index: " DEF ORANGE;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			exit(1);
		if (cmd.empty())
			std::cout << RED"\t\tAn index is expected !" DEF << std::endl;
		else {
			bool	isdigit = true;
			for (size_t j = 0; j != cmd.size(); j++) {
				if (!std::isdigit(cmd[j]) && cmd[j] != '-') {
					std::cout << RED"\t\tOnly numbers are expected !" DEF << std::endl;
					isdigit = false;
					break;
				}
			}
			if (!isdigit)
				continue;
			index = std::atoi(cmd.c_str()) - 1;
			if (index > i - 1 || index < 0) {
				std::cout << RED"\tThis index doesn't exist. Please enter a valid index !" DEF << std::endl;
				continue;
			}
			else {
				displayContact(index);
				return ;
			}
		}
	}
	return ;
}
