/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:46:15 by yu                #+#    #+#             */
/*   Updated: 2024/01/19 21:10:48 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class	Point{
	public:
		// constructor & destructor
		Point();
		Point(Fixed x, Fixed y);
		Point(const Point& other);
		~Point();
		Point&	Point::operator=(Point other);

	private:
		const Fixed	_x;
		const Fixed	_y;

};
