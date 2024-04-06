/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:38:37 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/05 12:22:48 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_H
# define ZOMBIE_CLASS_H

# include <iostream>

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

class Zombie {

public:

	Zombie(void);
	~Zombie(void);

	void	announce(void) const;
	void	setName(std::string data);

private:

	std::string	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif