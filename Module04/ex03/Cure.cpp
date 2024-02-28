/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/02/28 22:11:55 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() {
	// std::cout << "Default constructor of Cure called" << std::endl;
	AMateria::_type = "cure";
}

Cure::Cure(const Cure& other) {
	// std::cout << "Copy constructor of Cure called" << std::endl;
	*this = other;
}

Cure&	Cure::operator=(const Cure& other) {
	// std::cout << "Copy assignment of Cure operator called" << std::endl;
	if (this != &other)
		AMateria::_type = other._type;
	return *this;
}

Cure::~Cure() {
	// std::cout << "Destructor of Cure called" << std::endl;
}

std::string	const & Cure::getType() const {
	return (AMateria::_type);
}

AMateria* Cure::clone() const {
	return new Cure();
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() << "'s wounds *" << std::endl;
}
