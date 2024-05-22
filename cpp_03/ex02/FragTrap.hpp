/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:46:41 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/21 19:50:03 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_CLASS_H
# define FRAGTRAP_CLASS_H

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:

	FragTrap();
	FragTrap(const FragTrap& cpy);
	FragTrap&	operator=(const FragTrap& cpy);
	virtual ~FragTrap();

	FragTrap(const std::string& name);

	void	highFivesGuys();
};

#endif
