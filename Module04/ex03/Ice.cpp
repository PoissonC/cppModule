/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/02/27 22:37:20 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	// std::cout << "Default constructor of Ice called" << std::endl;
	AMateria::_type = "ice";
}

Ice::Ice(const Ice& other) {
	// std::cout << "Copy constructor of Ice called" << std::endl;
	*this = other;
}

Ice&	Ice::operator=(const Ice& other) {
	// std::cout << "Copy assignment of Ice operator called" << std::endl;
	if (this != &other)
		AMateria::_type = other._type;
	return *this;
}

Ice::~Ice() {
	// std::cout << "Destructor of Ice called" << std::endl;
}

std::string	const & Ice::getType() const {
	return (AMateria::_type);
}

AMateria* Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}
