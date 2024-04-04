/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:12:10 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/02 12:26:42 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

# include <iostream>
# include <cstring>

using std::cout;
using std::cin;
using std::endl;

/*-----------COLORS-UTILS-----------*/
# define DEF "\033[0m"
# define BOLD "\033[1m"
# define UNDERLINE "\033[4m"
# define UP "\033[A"
# define CLEAR "\033[2J\033[1;1H"

/*--------------COLORS--------------*/
# define RED "\033[31;2m"
# define BLACK "\033[38;5;238m"
# define BLUE "\033[38;5;153m"
# define GREEN "\033[38;5;48m"
# define YELLOW "\033[38;5;226m"
# define ORANGE "\033[38;5;202m"
# define PINK "\033[38;5;198m"
# define PURPLE "\033[38;5;147m"
# define CYAN "\033[36m"

class Contact {

public:

	Contact(void);
	~Contact(void);

	std::string	getFirstname(void) const;
	std::string	getLastname(void) const;
	std::string	getNickname(void) const;
	std::string	getPhonenumber(void) const;
	std::string	getDarkestsecret(void) const;

	void		setFirstname(std::string data);
	void		setLastname(std::string data);
	void		setNickname(std::string data);
	void		setPhonenumber(std::string data);
	void		setDarkestsecret(std::string data);

private:

	std::string	_firstname;
	std::string	_lastname;
	std::string	_nickname;
	std::string	_phonenumber;
	std::string	_darkestsecret;
};

#endif
