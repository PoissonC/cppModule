/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:21:24 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/04 22:56:58 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <iostream>
#include <string>
#include <cerrno>
#include <climits>
#include <cstdlib>

typedef enum e_type {
	ERR = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
} t_type;

class ScalarConverter
{
	private:
		ScalarConverter();
		static t_type	check_type(std::string & tar);
		static bool		convert_char(std::string & orign);
		static bool		convert_int(std::string & orign);
		static bool		convert_float(std::string & orign);
		static bool		convert_double(std::string & orign);
	public:
		static bool		convert(std::string & orign);
};
