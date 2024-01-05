/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/06 02:24:10 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// constructor & destructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Default constructor of ScavTrap called" << std::endl;
	this->setHp(100);
	this->setEp(50);
	this->setAd(20);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other){
	std::cout << "Copy constructor of ScavTrap called" << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "Copy assignment operator of ScavTrap called" << std::endl;
	if (this != &other) {
		this->setName(other.getName());
		this->setHp(other.getHp());
		this->setEp(other.getEp());
		this->setAd(other.getAd());
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor of ScavTrap called" << std::endl;
}

// member functions

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << this->getName() << " has enterred in Gate keeper mode.\n";
}