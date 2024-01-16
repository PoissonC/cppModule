/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:46:15 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:34:45 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class	AMateria{
	public:
		// Constructors and Destructors
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();
		// ***
		
		// Getters and Setters
		std::string const & getType() const; //Returns the materia type
		// ***

		// Member functions
		virtual void		use(ICharacter& target);
		virtual AMateria*	clone() const = 0;
		// ***
	protected:
		std::string	_type;
};
