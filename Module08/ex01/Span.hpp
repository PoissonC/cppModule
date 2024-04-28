/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:32:34 by ychen2            #+#    #+#             */
/*   Updated: 2024/04/28 14:54:23 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <vector>
#include <algorithm>
#include <iostream>
class Span {
	public:
		// OCF
		Span(unsigned int N);
		Span(const Span & other);
		Span&	operator=(const Span & other);
		~Span();

		// Member funcs
		void	addNumber(int new_num);
		template <typename Iter>
		void	addNumberChunck(Iter new_nums_begin, Iter new_nums_end) {
			unsigned int ct = 0;
			for (Iter it = new_nums_begin; it != new_nums_end; it++) {
				ct++;
			}
			std::cout << ct << std::endl;
			if (_vec.size() + ct > this->_number)
				throw AlreadyFull();
			for (Iter it = new_nums_begin; it != new_nums_end; it++) {
				_vec.push_back(*it);
			}
		}
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