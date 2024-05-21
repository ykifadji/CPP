/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:53:38 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 15:19:00 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

# include <iostream>
# include <cstdlib>
# include <iomanip>
# include <cstring>
# include "Contact.hpp"

# define PIPE "\033[38;5;202m|\033[0m"

class PhoneBook {
public:

	PhoneBook(void);
	~PhoneBook(void);

	void		displayContact(int index);
	int			parsNumber(std::string input);
	void		parsIndex(void);
	void		addContact(void);
	void		updatePhoneBook(void);
	void		printDir(void);
	std::string	updateName(std::string str);

private:

	Contact		contact[8];
	std::string	input;
	static int	i;
};

#endif
