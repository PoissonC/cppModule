/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:25:15 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("Non") {
	std::cout << "Default constructor of WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "Copy constructor of WrongAnimal called" << std::endl;
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "Copy assignment of WrongAnimal operator called" << std::endl;
	type = other.type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor of WrongAnimal called" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return (type);
}


void	WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound?" << std::endl;
}
