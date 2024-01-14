/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:44:47 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Non") {
	std::cout << "Default constructor of Animal called" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Copy constructor of Animal called" << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal& other) {
	std::cout << "Copy assignment of Animal operator called" << std::endl;
	type = other.type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Destructor of Animal called" << std::endl;
}

std::string	Animal::getType( void ) const {
	return (type);
}


void	Animal::makeSound() const {
	std::cout << "Animal sound?" << std::endl;
}
