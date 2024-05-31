/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:25:51 by ykifadji          #+#    #+#             */
/*   Updated: 2024/05/23 14:08:33 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_CLASS_H
# define WRONGCAT_CLASS_H

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:

	WrongCat();
	WrongCat(const WrongCat& cpy);
	WrongCat&	operator=(const WrongCat& cpy);
	~WrongCat();

	void	makeSound() const;

};

#endif
