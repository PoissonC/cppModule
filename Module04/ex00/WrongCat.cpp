/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:22:42 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "Default constructor of WrongCat called" << std::endl;
	WrongAnimal::type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other) {
	std::cout << "Copy constructor of WrongCat called" << std::endl;
	*this = other;
}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	std::cout << "Copy assignment of WrongCat operator called" << std::endl;
	WrongAnimal::type = other.type;
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor of WrongCat called" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << "meow meow~" << std::endl;
}