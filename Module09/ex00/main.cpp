/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:12:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/14 23:52:53 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <exception>

int main(int ac, char **av) {
	if (ac > 2) {
		std::cerr << "Error: Wrong number of argument." << std::endl;
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
			std::string	date = line.substr(0, 10);
			std::map<std::string, double>::iterator it = dict.lower_bound(date);
			if (it == dict.begin() && it->first != date) {
				std::cerr << "No data avaiable for the input date." << std::endl;
				continue;
			}
			else {
				if (it->first != date)
					--it;
				std::cout << date << " => " << val << " = " << val * it->second << std::endl;
			}
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
