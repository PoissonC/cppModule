/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/21 15:31:41 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : m_p(new PointImpl(0, 0)) {
	std::cout << "Default constructor without arguments of Point called" << std::endl;
}

Point::PointImpl::PointImpl() : _x(0), _y(0) {
}

Point::Point(Fixed x, Fixed y) : m_p(new PointImpl(x, y)) {
	std::cout << "Default constructor with Fixed arguments of Point called" << std::endl;
}

Point::PointImpl::PointImpl(Fixed x, Fixed y) : _x(x), _y(y) {
}

Point::Point(const float x, const float y) : m_p(new PointImpl(x, y)) {
	std::cout << "Default constructor with float arguments of Point called" << std::endl;
}

Point::PointImpl::PointImpl(const float x, const float y) : _x(x), _y(y){
}

Point::Point(const Point& other) : m_p(new PointImpl(other.getX(), other.getY())) {
	std::cout << "Copy constructor of Point called" << std::endl;
}


void	Point::swap(Point &tar) {
	Point::PointImpl	*temp = this->m_p;
	this->m_p = tar.m_p;
	tar.m_p = temp;
}

Point&	Point::operator=(Point other) {
	std::cout << "Copy assignment operator of Point called" << std::endl;
	this->swap(other);
	return *this;
}

Point::~Point() {
	std::cout << "Destructor of Point called" << std::endl;
	delete m_p;
}

Fixed	Point::getX() const {
	return (m_p->_x);
}

Fixed	Point::getY() const {
	return (m_p->_y);
}