/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/15 00:01:23 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <string>
#include <iostream>
#include <exception>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "Error: Wrong number of argument." << std::endl;
		return 1;	
	}
	std::string str = av[1];
	try {
		RPN(str);
	}
	catch (std::exception &e) {
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}
