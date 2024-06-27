/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShruberryCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 14:12:43 by ykifadji          #+#    #+#             */
/*   Updated: 2024/06/27 14:16:32 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class ShruberryCreationForm : public AForm {
public:
	ShruberryCreationForm();
	ShruberryCreationForm(const ShruberryCreationForm& cpy);
	ShruberryCreationForm&	operator=(const ShruberryCreationForm& other);
	~ShruberryCreationForm();
};
