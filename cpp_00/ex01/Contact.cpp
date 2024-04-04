/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:11:14 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/02 10:37:32 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {

	std::cout << BOLD GREEN "Constructor Contact called" DEF << std::endl;
	return ;
}

Contact::~Contact(void) {

	std::cout << BOLD RED "Destructor Contact called" DEF << std::endl;
	return ;
}

std::string	Contact::getFirstname(void) const {

	return (this->_firstname);
}

std::string	Contact::getLastname(void) const {

	return (this->_lastname);
}

std::string	Contact::getNickname(void) const {

	return (this->_nickname);
}

std::string	Contact::getPhonenumber(void) const {

	return (this->_phonenumber);
}

std::string	Contact::getDarkestsecret(void) const {

	return (this->_darkestsecret);
}

void	Contact::setFirstname(std::string data) {

	this->_firstname = data;
	return ;
}

void	Contact::setLastname(std::string data) {

	this->_lastname = data;
	return ;
}

void	Contact::setNickname(std::string data) {

	this->_nickname = data;
	return ;
}

void	Contact::setPhonenumber(std::string data) {

	this->_phonenumber = data;
	return ;
}

void	Contact::setDarkestsecret(std::string data) {

	this->_darkestsecret = data;
	return ;
}
