/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 23:25:19 by yu                #+#    #+#             */
/*   Updated: 2024/01/12 12:19:57 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	replaceAllOccurrences(const std::string &source, const std::string &from, const std::string &to) {
	size_t		startPos = 0;
	size_t		lastPos = 0;
	std::string	ret = "";

	startPos = source.find(from, startPos);
	while (startPos != std::string::npos) {
		ret += source.substr(lastPos, startPos - lastPos);
		ret += to;
		startPos += from.length();
		lastPos = startPos;
		startPos = source.find(from, startPos);
	}
	ret += source.substr(lastPos, startPos - lastPos);
	return ret;
}

int	main(int argc, char* argv[]) {
	//check arguments number
	if (argc != 4) {
		std::cout << "Wrong number of arguments." << std::endl;
		return 1;
	}

	// set up variables
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	// check if file exists
	std::ifstream inFile(filename);
	if (!inFile) {
		std::cerr << "Cannot open file: " << filename << std::endl;
		return 1;
	}

	// check if s1 is empty
	if (s1.empty()) {
		std::cerr << "s1 is empty." << std::endl;
		return 1;
	}

	// check if s2 is empty
	if (s2.empty()) {
		std::cerr << "s2 is empty." << std::endl;
		return 1;
	}

	// create new file
	std::string newFilename = filename + ".replace";
	std::ofstream outFile(newFilename);
	if (!outFile) {
		std::cerr << "Cannot create file: " << newFilename << std::endl;
		return 1;
	}

	// 
	std::string line;
	while (std::getline(inFile, line)) {
		outFile << replaceAllOccurrences(line, s1, s2) << "\n";
	}

	inFile.close();
	outFile.close();
	return 0;
}
