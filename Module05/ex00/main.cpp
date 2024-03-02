/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 16:07:52 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/02 20:01:40 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("John", 50);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		Bureaucrat invalidBureaucrat("Invalid", 0);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("Ben", 1);
		std::cout << bureaucrat << std::endl;

		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;

		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;

		Bureaucrat invalidBureaucrat("Invalid", 200);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Bureaucrat bureaucrat("Leo", 150);
		std::cout << bureaucrat << std::endl;

		Bureaucrat copy(bureaucrat);
		std::cout << copy << std::endl;

		Bureaucrat copy2 = copy;
		std::cout << copy2 << std::endl;

		copy2.incrementGrade();
		copy2 = copy;
		std::cout << copy2 << std::endl;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat invalidBureaucrat("Invalid", 200);
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
    return 0;
}