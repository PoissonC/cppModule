/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:46:15 by yu                #+#    #+#             */
/*   Updated: 2024/01/21 15:30:46 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"

class	Point {
	public:
		// constructor & destructor
		Point();
		Point(Fixed x, Fixed y);
		Point(const float x, const float y);
		Point(const Point& other);
		~Point();
		Point&	operator=(Point other);

		//getter
		Fixed	getX() const;
		Fixed	getY() const;
	private:
		class		PointImpl;
		PointImpl	*m_p;
		void		swap(Point &tar);
};

class Point::PointImpl {
	public:
		PointImpl();
		PointImpl(Fixed x, Fixed y);
		PointImpl(const float x, const float y);
		
		//contents
		const Fixed	_x;
		const Fixed	_y;
};

