/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:46:15 by yu                #+#    #+#             */
/*   Updated: 2024/01/16 18:16:26 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class	Fixed{
	public:
		// constructor & destructor
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();

		// member functions
		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		int 	toInt( void ) const;
		float	toFloat( void ) const;

		// asseigned operator overloading
		Fixed&			operator=(const Fixed& other);

		// 4 increment/decrement operators overloading
		Fixed&			operator++();
		Fixed&			operator--();
		Fixed			operator++(int);
		Fixed			operator--(int);

		// max, min overload
		static Fixed&	max(Fixed& a, Fixed& b);
		static Fixed&	min(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);


	private:
		int					fp_value;
		static const int	fp_bits = 8;

};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

// 6 comparison operators overload
bool			operator>(const Fixed& a, const Fixed& b);
bool			operator<(const Fixed& a, const Fixed& b);
bool			operator>=(const Fixed& a, const Fixed& b);
bool			operator<=(const Fixed& a, const Fixed& b);
bool			operator==(const Fixed& a, const Fixed& b);
bool			operator!=(const Fixed& a, const Fixed& b);

// 4 arithmetic operators overload
Fixed			operator+(const Fixed& a, const Fixed& b);
Fixed			operator-(const Fixed& a, const Fixed& b);
Fixed			operator*(const Fixed& a, const Fixed& b);
Fixed			operator/(const Fixed& a, const Fixed& b);
