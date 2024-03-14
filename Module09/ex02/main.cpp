/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/15 00:24:29 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <string>
#include <iostream>
#include <exception>

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: Wrong number of argument." << std::endl;
		return 1;	
	}

	try {
	}
	catch (std::exception &e) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}
