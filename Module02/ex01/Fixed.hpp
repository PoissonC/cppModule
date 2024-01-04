/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:46:15 by yu                #+#    #+#             */
/*   Updated: 2023/12/05 16:05:44 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cmath>

class	Fixed{
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed& other);
		~Fixed();
		Fixed&			operator=(const Fixed& other);
		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		int 	toInt( void ) const;
		float	toFloat( void ) const;
		
	private:
		int					fp_value;
		static const int	fp_bits = 8;

};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif