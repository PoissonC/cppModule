/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:12:48 by ychen2            #+#    #+#             */
/*   Updated: 2024/02/27 22:31:54 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"

class	Cure : public AMateria{
	public:
		Cure();
		Cure(const Cure& other);
		Cure& operator=(const Cure& other);
		~Cure();

		std::string const & getType() const; //Returns the materia type
		// ***

		// Member functions
		AMateria* clone() const;
		void use(ICharacter& target);
};