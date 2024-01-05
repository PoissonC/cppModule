/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:30 by yu                #+#    #+#             */
/*   Updated: 2024/01/05 23:25:31 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
	this->name = name;
	this->is_weapon = false;
}

HumanB::~HumanB() {
	std::cout << this->name << " is destroyed.\n";
}

void	HumanB::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
	is_weapon = true;
}

void	HumanB::attack(void) {
	if (is_weapon)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " attacks with bared hands." << std::endl;
}
