/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:12 by yu                #+#    #+#             */
/*   Updated: 2024/01/26 22:11:22 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point	a(0, 0);
	Point	b(0, 4);
	std::cout <<"\033[31m";
	Point	c(4, 0);
	std::cout << "\033[32m";
	Point	P(0.5f, 3);

	std::cout << "\033[33m";
	Point	ts = P;
	std::cout << "\033[0m";
	//2.5f, 2 -> not
	//3.5f, 0.5f - > not (on the line)
	//2, 1 -> yes (symmetric)
	//0.5f, 3 -> yes (symmetric)

	if	(bsp(a, b ,c, P))
		std::cout << "The point is in the triangle." << std::endl;
	else
		std::cout << "The point is not in the triangle." << std::endl;

	return 0;
}