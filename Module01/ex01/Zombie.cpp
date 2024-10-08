/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:58 by yu                #+#    #+#             */
/*   Updated: 2024/01/05 23:25:59 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
	this->name = name;
	if (name[0])
		std::cout << "Zombie " << this->name << " has spwaned\n";
	else
		std::cout << "A zombie in a Horde has spwaned\n";
}

Zombie::~Zombie() {
	std::cout << this->name << " is destroyed.\n";
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void	Zombie::setName(const std::string& name) {
	this->name = name;
}