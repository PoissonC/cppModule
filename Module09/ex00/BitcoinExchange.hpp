/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 22:58:52 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/14 05:48:19 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <exception>
#include <string>
#include <algorithm>
#include <map>
#include <locale> //std::isdigit

class Bad_Input : public std::exception {
	virtual const char * what() const throw();
};

class Parse_Value_Fail_Too_Large : public std::exception {
	virtual const char * what() const throw();
};

class Parse_Value_Fail_Negative : public std::exception {
	virtual const char * what() const throw();
};

bool	parse_dict(std::map<std::string, double> & dict);
double	parse_line(std::string & line); //throw	
void	check_date(std::string date); //throw
