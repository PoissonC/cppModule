/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/06 02:26:43 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// constructor & destructor
DiamondTrap::DiamondTrap(std::string name) : FragTrap(name), ScavTrap(name), _name(name) {
	std::cout << "Default constructor of DiamondTrap called" << std::endl;
	ScavTrap::setName(name + "_clap_name");
	ScavTrap::setHp(FragTrap::getHp());
	ScavTrap::setAd(FragTrap::getAd());
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other), ScavTrap(other){
	std::cout << "Copy constructor of DiamondTrap called" << std::endl;
	FragTrap::setName(FragTrap::getName() + "_clap_name");
	*this = other;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "Copy assignment operator of DiamondTrap called" << std::endl;
	if (this != &other) {
		this->_name = other._name;
		ScavTrap::setName();
		ScavTrap::setHp(FragTrap::getHp());
		ScavTrap::setAd(FragTrap::getAd());
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor of DiamondTrap called" << std::endl;
}

// member functions
void	DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name is " << this->_name << std::endl;
	std::cout << "ClapTrap name is " << ScavTrap::getName() << std::endl;
}

void	DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount) {
	ScavTrap::takeDamage(amount);
}

void	DiamondTrap::beRepaired(unsigned int amount) {
	ScavTrap::beRepaired(amount);
}
