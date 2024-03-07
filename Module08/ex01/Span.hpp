/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:32:34 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 23:04:02 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <vector>
#include <algorithm>

class Span {
	public:
		// OCF
		Span(unsigned int N);
		Span(const Span & other);
		Span&	operator=(const Span & other);
		~Span();

		// Member funcs
		void	addNumber(int new_num);
		int		shortestSpan();
		int		longestSpan();


		// Exception
		class AlreadyFull : public std::exception {
			const char* what() const throw();
		};
		class NoSpanFound : public std::exception {
			const char* what() const throw();
		};
	private:
		unsigned int		_number;
		std::vector<int>	_vec;
};