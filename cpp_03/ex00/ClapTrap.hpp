/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 08:44:01 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 13:02:30 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H

#include <iostream>

# define DEF "\033[0m"
# define RED "\033[1m\033[31;2m"
# define GREEN "\033[1m\033[38;5;48m"
# define CYAN "\033[36m"
# define ORANGE "\033[1m\033[38;5;202m"
# define BLUE "\033[1m\033[38;5;153m"

class ClapTrap {

public:

	ClapTrap(void);
	ClapTrap&	operator=(const ClapTrap& cpy);
	ClapTrap(const ClapTrap& cpy);
	~ClapTrap(void);

	ClapTrap(const std:: string& name);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

private:

	std::string	_name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;
};

#endif