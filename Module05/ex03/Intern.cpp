/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 18:05:34 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 22:47:21 by ychen2           ###   ########.fr       */
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

Intern::~Intern() {
}

Form * Intern::makeForm(const std::string & formName, const std::string & target) {
	const struct s_forms	forms[3] = {
		{"presidential pardon", *createPPF},
		{"robotomy request", *createRRF},
		{"shrubbery creation", *createSCF}
	};

	for (int i = 0; i < 3; i++) {
		if (forms[i].formName == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].formFactory(target);
		}
	}
	std::cout << "Error: no form is named as " << formName << std::endl;
	return NULL;
}

Form*	createPPF(const std::string & tar) {
	return new PresidentialPardonForm(tar);
}

Form*	createRRF(const std::string & tar) {
	return new RobotomyRequestForm(tar);
}

Form*	createSCF(const std::string & tar) {
	return new ShrubberyCreationForm(tar);
}