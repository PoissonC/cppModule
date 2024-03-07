/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 23:10:22 by ychen2            #+#    #+#             */
/*   Updated: 2024/03/07 22:09:04 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	iter(T* array, int length, void (*func)(T&)) {
	for (int i = 0; i < length; i++) {
		func(array[i]);
	}
}
