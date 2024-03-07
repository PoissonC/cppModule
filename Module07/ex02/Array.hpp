/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:10:22 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 21:39:16 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

template <typename T>
class Array {
	public:
		// OCF
		Array();
		Array(const unsigned int & n);
		Array(const Array &other);
		Array& operator=(const Array &other);
		~Array();

		// Subcript overload
		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;

		// size
		unsigned int	size() const;

		// Execption
		class out_of_range : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		
	private:
		T				*_data;
		unsigned int	_size;
};

#include "Array.tpp"