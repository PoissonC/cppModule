/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:42 by yu                #+#    #+#             */
/*   Updated: 2024/01/05 23:25:44 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->type = type;
}

Weapon::~Weapon() {
	std::cout << this->type <<" is destroyed.\n";
}

const std::string	&Weapon::getType() const {
	return (this->type);
}

void	Weapon::setType(std::string type) {
	this->type = type;
}
