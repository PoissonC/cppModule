/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 15:19:37 by ychen2            #+#    #+#             */
/*   Updated: 2024/02/27 23:58:31 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

AMateria::AMateria() {
}

AMateria::AMateria(const AMateria& other) : _type(other._type) {
}

AMateria& AMateria::operator=(const AMateria& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

AMateria::~AMateria() {
}

std::string const & AMateria::getType() const {
	return _type;
}

void AMateria::use(ICharacter& target) {
	std::cout << "Using AMateria on " << target.getName() << std::endl;
}