/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:21:24 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/12 23:35:17 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cerrno>
#include <climits>
#include <limits>
#include <cstdlib>

typedef enum e_type {
	ERR = 0,
	CHAR,
	INT,
	FLOAT,
	DOUBLE
} t_type;

class ScalarConverter {
	private:
		ScalarConverter();
	public:
		static bool		convert(std::string & orign);
};
