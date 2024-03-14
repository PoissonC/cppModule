/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 23:51:57 by yu                #+#    #+#             */
/*   Updated: 2024/03/15 00:16:55 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN(std::string & str) {
	if (str.length() == 0)
		throw std::exception();
	std::stack<double>	stk;
	for (size_t i = 0; i < str.length(); i++) {
		if (std::isdigit(str[i])) {
			stk.push(std::strtod(&str[i], NULL));
			size_t dot_ct = 0;
			while (std::isdigit(str[i + 1]) || str[i + 1] == '.') {
				if (str[i + 1] == '.')
					dot_ct++;
				if (dot_ct > 1)
					throw std::exception();
				i++;
			}
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			if (stk.size() < 2)
				throw std::exception();
			double a = stk.top();
			stk.pop();
			double b = stk.top();
			stk.pop();
			if (str[i] == '+')
				stk.push(b + a);
			else if (str[i] == '-')
				stk.push(b - a);
			else if (str[i] == '*')
				stk.push(b * a);
			else if (str[i] == '/') {
				if (a == 0)
					throw std::exception();
				stk.push(b / a);
			}
		}
		else if (str[i] != ' ')
			throw std::exception();
	}
	if (stk.size() != 1)
		throw std::exception();
	std::cout << stk.top() << std::endl;
}