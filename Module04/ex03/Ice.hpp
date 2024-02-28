/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:12:48 by ychen2            #+#    #+#             */
/*   Updated: 2024/02/27 23:49:50 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "AMateria.hpp"

class	Ice : public AMateria{
	public:
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		~Ice();

		std::string const & getType() const; //Returns the materia type
		// ***

		// Member functions
		AMateria* clone() const;
		void use(ICharacter& target);
};
