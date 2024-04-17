/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:28:05 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/09 18:28:31 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB {

public:

	HumanB(void);
	~HumanB(void);

	void	attack(void);
	void	setName(std::string data);

private:

	Weapon		_weapon;
	std::string	_name;
};

#endif
