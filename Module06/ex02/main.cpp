/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:24:14 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/13 00:00:06 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Funcs.hpp"
#include <ctime>   // For std::time(), to seed the random number generator
#include <cstdlib> // For std::rand() and std::srand()

int main() {
	//seed the random value lists
	std::srand(std::time(NULL));

	Base *ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;
	return (0);
}