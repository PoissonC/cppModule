/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/16 19:46:31 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	std::cout << "Default constructor of Fixed called" << std::endl;
	this->fp_value = 0;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor of Fixed called" << std::endl;
	this->fp_value = value << this->fp_bits;
}

Fixed::Fixed(const float value) {
	std::cout << "Float constructor of Fixed called" << std::endl;
	this->fp_value = roundf(value * (1 << this->fp_bits));
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor of Fixed called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator of Fixed called" << std::endl;
	this->fp_value = other.fp_value;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor of Fixed called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	return this->fp_value;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fp_value = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->fp_value / (float)(1 << this->fp_bits);
}

int	Fixed::toInt( void ) const {
	return this->fp_value >> this->fp_bits;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}


// operator overloading

std::ostream&	operator<<(std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}

bool	operator>(const Fixed& a, const Fixed& b) {
	return a.getRawBits() > b.getRawBits();
}

bool	operator<(const Fixed& a, const Fixed& b) {
	return a.getRawBits() < b.getRawBits();
}

bool	operator>=(const Fixed& a, const Fixed& b) {
	return a.getRawBits() >= b.getRawBits();
}

bool	operator<=(const Fixed& a, const Fixed& b) {
	return a.getRawBits() <= b.getRawBits();
}

bool	operator==(const Fixed& a, const Fixed& b) {
	return a.getRawBits() == b.getRawBits();
}

bool	operator!=(const Fixed& a, const Fixed& b) {
	return a.getRawBits() != b.getRawBits();
}

// 4 arithmetic operators overload

// use float to +-*/
Fixed	operator+(const Fixed& a, const Fixed& b) {
	return Fixed(a.toFloat() + b.toFloat());
}

Fixed	operator-(const Fixed& a, const Fixed& b) {
	return Fixed(a.toFloat() - b.toFloat());
}

Fixed	operator*(const Fixed& a, const Fixed& b) {
	return Fixed(a.toFloat() * b.toFloat());
}

Fixed	operator/(const Fixed& a, const Fixed& b) {
	return Fixed(a.toFloat() / b.toFloat());
}


// 4 increment/decrement operators overloading

Fixed&	Fixed::operator++() {
	this->fp_value++;
	return *this;
}

Fixed&	Fixed::operator--() {
	this->fp_value--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return tmp;
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return tmp;
}
