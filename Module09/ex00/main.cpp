/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/14 05:49:11 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>

int main(int ac, char **av) {
	if (ac > 2) {
		std::cout << "Error: Wrong number of argument." << std::endl;
		return 1;	
	}

	// Open input file
	std::ifstream inFile(av[1]);
	if (!inFile) {
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}
	std::string	line;
	std::getline(inFile, line);
	if (line != "date | value") {
		std::cerr << "Error: Wrong input file." << std::endl;
		return 1;
	}

	// Build dict
	std::map<std::string, double>	dict;
	if (parse_dict(dict)) {
		std::cerr << "Error: could not build the database" << std::endl;
		return 1;
	}

	while (std::getline(inFile, line)) {
		try {
			double	val = parse_line(line);
			//use dict.lower_bound - 1
		}
		catch(std::exception & e) {
			if (dynamic_cast<Bad_Input*>(&e))
				std::cerr << e.what() << line << std::endl;
			else
				std::cerr << e.what() << std::endl;
		}
	}
	return 0;
}
