/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 22:07:49 by ychen2            #+#    #+#             */
/*   Updated: 2024/04/26 17:12:31 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::iterator easyfind(T& container, int value) {
	for (typename T::iterator it = container.begin(); it != container.end(); it++) {
		if (*it == value) {
			return it;
		}
	}
	return container.end();
}