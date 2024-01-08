/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:26:21 by yu                #+#    #+#             */
/*   Updated: 2024/01/08 15:44:34 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(const std::string& name) {
	this->name = name;
	std::cout << "Zombie " << this->name << " has spwaned\n";
}

Zombie::~Zombie() {
	std::cout << this->name << " is destroyed.\n";
}

void	Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}