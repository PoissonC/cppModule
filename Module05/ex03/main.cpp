/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:52 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/03 21:47:49 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	// PresidentialPardonForm test
	try {
		PresidentialPardonForm form("The First Criminal");
		std::cout << form << std::endl;

		Bureaucrat bureaucrat("Kim", 6);
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		PresidentialPardonForm form("The Second Criminal");
		std::cout << form << std::endl;

		Bureaucrat bureaucrat("Kim", 5);
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// RobotomyRequestForm test
	try {
		RobotomyRequestForm form("The First Target");
		std::cout << form << std::endl;

		Bureaucrat bureaucrat("John", 10);
		form.execute(bureaucrat);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		RobotomyRequestForm form("The Second Target");
		std::cout << form << std::endl;

		Bureaucrat bureaucrat("John", 10);
		form.beSigned(bureaucrat);
		for (int i = 0; i < 10; i++)
			form.execute(bureaucrat);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// ShrubberyCreationForm test
	try {
		ShrubberyCreationForm form("The First house");
		std::cout << form << std::endl;

		Bureaucrat bureaucrat("Bill", 10);
		form.execute(bureaucrat);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		ShrubberyCreationForm form("The Second house");
		std::cout << form << std::endl;

		Bureaucrat bureaucrat("Bill", 10);
		form.beSigned(bureaucrat);
		form.execute(bureaucrat);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	//copy test
	try {
		ShrubberyCreationForm form("The House");
		std::cout << form << std::endl;

		ShrubberyCreationForm copy(form);
		std::cout << copy << std::endl;

		ShrubberyCreationForm copy2 = copy;
		std::cout << copy2 << std::endl;

		Bureaucrat bureaucrat("Bill", 150);
		copy2.beSigned(bureaucrat);

		copy2 = copy;
		std::cout << copy2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

    return 0;
}