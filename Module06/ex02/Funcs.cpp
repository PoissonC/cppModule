/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Funcs.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 23:39:40 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/13 00:10:11 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Funcs.hpp"
#include <cstdlib> // For std::rand() and std::srand()
#include <exception>

Base*	generate(void) {
	int	randomValue = std::rand();

	if (randomValue % 3 == 1) {
		return new A();
	}
	else if (randomValue % 3 == 2) {
		return new B();
	}
	else {
		return new C();
	}
}

void	identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Invalid pointer." << std::endl;
}

void	identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e){}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (const std::exception& e){}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception& e){}
}
