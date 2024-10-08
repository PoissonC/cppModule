/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:19:51 by ychen2            #+#    #+#             */
/*   Updated: 2024/02/27 23:54:48 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "ICharacter.hpp"

class	ICharacter;

class	AMateria {
	public:
		// Constructors and Destructors
		AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
		// ***
		
		// Getters and Setters
		std::string const& getType() const; //Returns the materia type
		// ***

		// Member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
		// ***
	protected:
		std::string	_type;
};
