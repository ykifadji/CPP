/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 09:45:03 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/27 15:16:59 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

public:

	ScavTrap();
	ScavTrap(const ScavTrap& cpy);
	ScavTrap&	operator=(const ScavTrap& cpy);
	~ScavTrap();

	ScavTrap(const std::string& name);

	virtual void	attack(const std::string& target);
	void			guardGate(void);
};

#endif
