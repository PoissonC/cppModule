/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/21 14:17:22 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
	std::cout << "Default constructor without arguments of Point called" << std::endl;
}

Point::Point(Fixed x, Fixed y) : _x(x), _y(y) {
	std::cout << "Default constructor with arguments of Point called" << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
	std::cout << "Copy constructor of Point called" << std::endl;
}

static void m_swap(Point& a, Point& b) {
    Point	tmp;

	tmp = a;
    a = b;
    b = tmp;
}

Point&	Point::operator=(Point other) {
	std::cout << "Copy assignment operator of Point called" << std::endl;
	m_swap(*this, other);
	return *this;
}

Point::~Point() {
	std::cout << "Destructor of Point called" << std::endl;
}

Fixed	Point::getX() const {
	return (_x);
}

Fixed	Point::getY() const {
	return (_y);
}