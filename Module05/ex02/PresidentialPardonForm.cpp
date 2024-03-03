/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:23:38 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 17:12:27 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : Form("presidential pardon", target, 25, 5) {
	// std::cout << "Default constructor of PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	// std::cout << "Destructor of PresidentialPardonForm called" << std::endl;
}

void	PresidentialPardonForm::action() const {
	std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
