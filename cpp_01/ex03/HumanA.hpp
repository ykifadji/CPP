/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:09:15 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/09 19:24:41 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA {

public:

	HumanA(Weapon weapon, std::string name);
	HumanA(void);
	~HumanA(void);

	void	attack(void);
	void	setName(std::string data);

private:

	Weapon		_weapon;
	std::string	_name;
};

#endif
