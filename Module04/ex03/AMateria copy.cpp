/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:44:47 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("Non") {
	std::cout << "Default constructor of AMateria called" << std::endl;
}

AMateria::AMateria(const AMateria& other) {
	std::cout << "Copy constructor of AMateria called" << std::endl;
	*this = other;
}

AMateria&	AMateria::operator=(const AMateria& other) {
	std::cout << "Copy assignment of AMateria operator called" << std::endl;
	type = other.type;
	return *this;
}

AMateria::~AMateria() {
	std::cout << "Destructor of AMateria called" << std::endl;
}

std::string	AMateria::getType( void ) const {
	return (type);
}

void	AMateria::makeSound() const {
	std::cout << "AMateria sound?" << std::endl;
}
