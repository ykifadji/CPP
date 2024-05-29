/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:21:38 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/29 10:42:34 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {

private:
	AMateria*	_materias[4];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& cpy);
	MateriaSource&	operator=(const MateriaSource& other);
	virtual ~MateriaSource();

	virtual void	learnMateria(AMateria* m);
	virtual AMateria*	createMateria(std::string const & type);
};