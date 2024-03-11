/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:24:19 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/12 02:36:17 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

t_type	check_type(std::string & tar);
bool	convert_char(std::string & orign);
bool	convert_int(std::string & orign);
bool	convert_float(std::string & orign);
bool	convert_double(std::string & orign);

ScalarConverter::ScalarConverter() {}

t_type	check_type(std::string & tar) {
	size_t			len = tar.length();
	unsigned int	dot_idx = 0;
	size_t			i = 0;
	if (tar.at(i) == '-')
		i++;
	for (; i < len && std::isdigit(tar[i]); i++);
	if (i == len) {
		return INT;
	}
	if (tar[i] == '.') {
		dot_idx = i++;
		for (; i < len && std::isdigit(tar[i]); i++);
	}
	if (i == len)
		return DOUBLE;
	if (tar[i] == 'f' && tar[i - 1] != '.' && dot_idx != 0)
		return FLOAT;
	if (tar.at(0) == '\'' && tar.at(len - 1) == '\'') {
		if (len != 3)
			return ERR;
		return CHAR;
	}
	return ERR;
}

bool	ScalarConverter::convert(std::string & orign) {
	t_type	orign_type = check_type(orign);

	if (orign_type == ERR) {
		if (orign == "nan" || orign == "nanf") {
			std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";
			return false;
		}
		if (orign == "+inf" || orign == "+inff") {
			std::cout << "char: impossible\nint: impossible\nfloat: +inff\ndouble: +inf\n";
			return false;
		}
		if (orign == "-inf" || orign == "-inff") {
			std::cout << "char: impossible\nint: impossible\nfloat: -inff\ndouble: inf\n";
			return false;
		}
		std::cerr << "Invalid input." << std::endl;
		return true;
	}
	else if (orign_type == CHAR)
		return convert_char(orign);
	else if (orign_type == INT)
		return convert_int(orign);
	else if (orign_type == FLOAT)
		return convert_float(orign);
	else
		return convert_double(orign);
}

bool	convert_char(std::string & orign) {
	char character = orign[1];
	std::cout << "char: '" << character << "'" <<std::endl;
	std::cout << "int: " << static_cast<int>(character) << std::endl;
	std::cout << "float: " << static_cast<float>(character) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(character) << ".0" << std::endl;
	return false;
}

bool	convert_int(std::string & orign) {
	long	value = std::strtol(orign.c_str(), NULL, 10);
	if (value > INT_MAX || value < INT_MIN) {
		std::cerr << "Int overflow" << std::endl;
		return true;
	}
	int		integer = static_cast<int>(value);
	if (integer > CHAR_MAX || integer < CHAR_MIN) {
		std::cout << "char: impossible" << std::endl;
	}
	else {
		if (integer >= 32 && integer <= 126)
			std::cout << "char: '" << static_cast<char>(integer) << "'" <<std::endl;
		else
			std::cout << "char:  Non displayable" << std::endl;
	}
	std::cout << "int: " << integer << std::endl;
	if (integer >= 1000000) {
		std::cout << "float: " << static_cast<float>(integer) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(integer) << std::endl;
	}
	else {
		std::cout << "float: " << static_cast<float>(integer) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(integer) << ".0" << std::endl;
	}
	return false;
}

bool	convert_float(std::string & orign) {
	errno = 0;
	float	floating = std::strtof(orign.c_str(), NULL);
	if (floating <= std::numeric_limits<float>::min() && floating > 0) {
		std::cerr << "Float underflow" << std::endl;
		return true;
	}
	else if (errno == ERANGE) {
		std::cerr << "Float overflow" << std::endl;
		return true;
	}
	if (floating > CHAR_MAX || floating < CHAR_MIN) {
		std::cout << "char: impossible" << std::endl;
	}
	else {
		if (static_cast<char>(floating) >= 32 && static_cast<char>(floating) <= 126)
			std::cout << "char: '" << static_cast<char>(floating) << "'" <<std::endl;
		else
			std::cout << "char:  Non displayable" << std::endl;
	}
	if (static_cast<int>(floating) == INT_MIN) {
		long long_int = std::strtol(orign.c_str(), NULL, 10);
		if (long_int < INT_MIN || long_int > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(floating) << std::endl;
	}
	else
		std::cout << "int: " << static_cast<int>(floating) << std::endl;
	std::cout << "float: " << floating << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floating) << std::endl;
	return false;
}

bool	convert_double(std::string & orign) {
	errno = 0;
	double	double_precision = std::strtod(orign.c_str(), NULL);
	if (errno == ERANGE) {
		std::cerr << "Double overflow" << std::endl;
		return true;
	}
	if (double_precision > CHAR_MAX || double_precision < CHAR_MIN) {
		std::cout << "char: impossible" << std::endl;
	}
	else {
		if (static_cast<char>(double_precision) >= 32 && static_cast<char>(double_precision) <= 126)
			std::cout << "char: '" << static_cast<char>(double_precision) << "'" <<std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
	}
	if (static_cast<int>(double_precision) == INT_MIN) {
		long long_int = std::strtol(orign.c_str(), NULL, 10);
		if (long_int < INT_MIN || long_int > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << static_cast<int>(double_precision) << std::endl;
	}
	else
		std::cout << "int: " << static_cast<int>(double_precision) << std::endl;
	std::cout << "float: " << static_cast<double>(double_precision) << "f" << std::endl;
	std::cout << "double: " << double_precision << std::endl;
	return false;
}
