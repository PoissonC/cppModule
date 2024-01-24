/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/24 17:39:41 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// constructor & destructor
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name) {
	std::cout << "Default constructor of DiamondTrap called" << std::endl;
	this->setEp(50);
	// std::cout << "Name of ClapTrap: " << ClapTrap::getName() << std::endl;
	// std::cout << "Name of FragTrap: " << FragTrap::getName() << std::endl;
	// std::cout << "Name of ScavTrap: " << ScavTrap::getName() << std::endl;
	// std::cout << "Hp: " << this->getHp() << std::endl;
	// std::cout << "Ep: " << this->getEp() << std::endl;
	// std::cout << "Ad: " << this->getAd() << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other) {
	std::cout << "Copy constructor of DiamondTrap called" << std::endl;
	*this = other;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "Copy assignment operator of DiamondTrap called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		ClapTrap::setName(other.getName());
		this->setHp(other.getHp());
		this->setEp(other.getEp());
		this->setAd(other.getAd());
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}

// member functions
void	DiamondTrap::takeDamage(unsigned int amount) {
	ScavTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	ScavTrap::beRepaired(amount);
}

void	DiamondTrap::whoAmI() {
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::getName() << std::endl;
}
