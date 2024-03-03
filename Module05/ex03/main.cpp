/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:52 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/03 22:45:34 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
	try {
		// presidential pardon test
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Poor Criminal");

		std::cout << *rrf << std::endl;

		Bureaucrat bureaucrat("Kim", 5);
		rrf->beSigned(bureaucrat);
		rrf->execute(bureaucrat);
		delete rrf;

		// robotomy request
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		std::cout << *rrf << std::endl;

		rrf->beSigned(bureaucrat);
		rrf->execute(bureaucrat);
		delete rrf;

		// shrubbery creation
		rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");

		std::cout << *rrf << std::endl;

		rrf->beSigned(bureaucrat);
		rrf->execute(bureaucrat);
		delete rrf;
		rrf = someRandomIntern.makeForm("Special Form", "You");
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

    return 0;
}