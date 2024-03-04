/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:24:19 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/04 23:05:07 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

t_type	ScalarConverter::check_type(std::string & tar) {
	size_t	len = tar.length();
	size_t	i = 0;
	if (tar.at(i) == '-')
		i++;
	for (; i < len && std::isdigit(tar[i]); i++);
	if (i == len) {
		return INT;
	}
	if (tar[i] == '.') {
		for (i++; i < len && std::isdigit(tar[i]); i++);
	}
	if (i == len)
		return DOUBLE;
	if (tar[i] == 'f')
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

bool	ScalarConverter::convert_char(std::string & orign) {
	char	character;

	std::cout << "is char\n";
	character = orign[1];
	if (std::isprint(character))
		std::cout << "char: '" << character << "\'" <<std::endl;
	else
		std::cout << "char:  Non displayable" << std::endl;
	
	std::cout << "int: " << static_cast<int>(character) << std::endl;
	std::cout << "float: " << static_cast<float>(character) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(character) << ".0" << std::endl;
	
}

bool	ScalarConverter::convert_int(std::string & orign) {
	int		integer;
	char	*end;

	std::cout << "is int\n";
	// std::istringstream(orign) >> integer;
	integer = static_cast<int>(orign);
	if (errno == ERANGE) {
		std::cerr << "Int overflow" << std::endl;
		return true;
	}
	if (std::isprint(integer))
		std::cout << "char: '" << static_cast<char>(integer) << "\'" <<std::endl;
	else
		std::cout << "char:  Non displayable" << std::endl;
	std::cout << "int: " << integer << std::endl;
	std::cout << "float: " << static_cast<float>(integer) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(integer) << ".0" << std::endl;
	return false;
}

bool	ScalarConverter::convert_float(std::string & orign) {
	char	character;
	int		integer;
	float	floating;
	double	double_precision;

	std::cout << "is float\n";
	std::istringstream(orign) >> floating;
}

bool	ScalarConverter::convert_double(std::string & orign) {
	char	character;
	int		integer;
	float	floating;
	double	double_precision;

	std::cout << "is double\n";
	std::istringstream(orign) >> double_precision;
}
