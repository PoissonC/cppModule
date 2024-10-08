/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:57:57 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/14 23:38:38 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const char * Bad_Input::what() const throw() {
	return "Error: bad input => ";
}

const char * Parse_Value_Fail_Too_Large::what() const throw() {
	return "Error: too large a number.";
}

const char * Parse_Value_Fail_Negative::what() const throw() {
	return "Error: not a positive number.";
}

bool	parse_dict(std::map<std::string, double> & dict) {
	std::ifstream	inFile("data.csv");
	if (!inFile)
		return true;
	std::string	line;
	std::getline(inFile, line);
	if (line != "date,exchange_rate")
		return true;
	while (std::getline(inFile, line))
		dict[line.substr(0, 10)] = std::strtod(line.substr(11).c_str(), NULL);
	inFile.close();
	return false;
}

double	parse_line(std::string & line) {
	if (line.size() < 14)
		throw Bad_Input();
	if (line.substr(10, 3) != " | ")
		throw Bad_Input();
	check_date(line.substr(0, 10));
	std::string	value = line.substr(13);
	{
		int dot_ct = 0;
		std::string::iterator it = value.begin();
		if (*it == '-')
			it++;
		for (; it != value.end(); it++) {
			if (!std::isdigit(*it) && *it != '.')
				throw Bad_Input();
			if (*it == '.')
				dot_ct++;
			if (dot_ct > 1)
				throw Bad_Input();
		}
	}
	errno = 0;
	double	ret = std::strtod(value.c_str(), NULL);
	if (errno == ERANGE)
		throw Bad_Input();
	if (ret > 1000)
		throw Parse_Value_Fail_Too_Large();
	if (ret < 0)
		throw Parse_Value_Fail_Negative();
	return ret;
}

void	check_date_format(std::string date) {
	if (date[4] != '-' || date[7] != '-')
		throw Bad_Input();
	for (size_t i = 0; i <= 3; i++)
		if (!std::isdigit(date[i]))
			throw Bad_Input();
	for (size_t i = 5; i <= 6; i++)
		if (!std::isdigit(date[i]))
			throw Bad_Input();
	for (size_t i = 8; i <= 9; i++)
		if (!std::isdigit(date[i]))
			throw Bad_Input();
}

static bool isLeapYear(int year) {
	return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

void	check_date(std::string date) {
	check_date_format(date);
	long	y = std::strtol(date.substr(0, 4).c_str(), NULL, 10);
	long	m = std::strtol(date.substr(5, 2).c_str(), NULL, 10);
	long	d = std::strtol(date.substr(8, 2).c_str(), NULL, 10);
	if (m < 1 || m > 12 || y < 0 || d < 1)
		throw Bad_Input();
	int daysInMonth[] = 
	{31, 28 + isLeapYear(y), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (d > daysInMonth[m - 1])
		throw Bad_Input();
}