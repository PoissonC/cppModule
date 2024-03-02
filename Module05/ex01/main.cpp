/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:52 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/02 23:58:32 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	// General tests
	try {
		Form form("The Contract", -1, 151);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	//
	try {
		Form form("The Contract", -1, 150);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	//
	try {
		Form form("The Special Contract", 132, 20);
		Bureaucrat bureaucrat("Dimakmak", 133);

		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
		bureaucrat.incrementGrade();
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	//copy test
	try {
		Form form("The Contract", 150, 150);
		std::cout << form << std::endl;

		Form copy(form);
		std::cout << copy << std::endl;

		Form copy2 = copy;
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