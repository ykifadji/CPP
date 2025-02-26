/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:22:32 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/31 08:07:22 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class AMateria;

class IMateriaSource {

public:
	virtual ~IMateriaSource() {};

	virtual void	learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(std::string const & type) = 0;
};
