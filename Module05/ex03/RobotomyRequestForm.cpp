/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:23:38 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 17:12:27 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("robotomy request", target, 72, 45) {
	// std::cout << "Default constructor of RobotomyRequestForm called" << std::endl;
	// Seed the random number generator
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm() {
	// std::cout << "Destructor of RobotomyRequestForm called" << std::endl;
}

void	RobotomyRequestForm::action() const {
std::cout << "Drilling noises..." << std::endl;	
	// Generate a random number and determine success or failure
	if (std::rand() % 2) {
		std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
	}
	else {
		std::cout << "The robotomy on " << this->getName() << " failed." << std::endl;
	}
}
