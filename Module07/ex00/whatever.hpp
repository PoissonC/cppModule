/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:10:22 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/04 23:18:44 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
void	swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T	min(const T& a, const T& b) {
	return (a < b) ? a : b;
}

template <typename T>
T	max(const T& a, const T& b) {
	return (a > b) ? a : b;
}
