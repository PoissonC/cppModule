/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:05:34 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 18:19:37 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern & other) {
	*this = other;
}

Intern & Intern::operator=(const Intern & other) {
	(void)other;
	return *this;
}

AForm * Intern::makeForm(const std::string & formName, const std::string & target) {
	if (formName == "shrubbery creation") {
		std::cout << "Intern creates " << formName << std::endl;
		return new ShrubberyCreationForm(target);
	} else if (formName == "robotomy request") {
		std::cout << "Intern creates " << formName << std::endl;
		return new RobotomyRequestForm(target);
	} else if (formName == "presidential pardon") {
		std::cout << "Intern creates " << formName << std::endl;
		return new PresidentialPardonForm(target);
	} else {
		std::cout << "Intern doesn't know how to create " << formName << std::endl;
		return NULL;
	}
}