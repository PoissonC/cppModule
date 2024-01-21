/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:08:25 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/21 15:04:03 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	det(Point const a, Point const b, Point const c) {
	// v1 = (a.getX() - c.getX(), a.getY() - c.getY())
	// v2 = (b.getX() - c.getX(), b.getY() - c.getY())
	return (a.getX() - c.getX()) * (b.getY() - c.getY()) - (a.getY() - c.getY()) * (b.getX() - c.getX());
}

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
	bool	has_pos, has_neg;
	Fixed	det1, det2, det3;

	det1 = det(a, b, point);
	det2 = det(b, c, point);
	det3 = det(c, a, point);

	// if on the line
	if (det1 == 0 || det2 == 0 || det3 == 0)
		return false;

	has_pos = det1 > 0 || det2 > 0 || det3 > 0;
	has_neg = det1 < 0 || det2 < 0 || det3 < 0;

	return !(has_pos && has_neg);
}
