/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:46:15 by yu                #+#    #+#             */
/*   Updated: 2024/01/26 22:00:44 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"

class	Cat : public Animal {
	public:
		//
		Cat();
		Cat(const Cat& other);
		Cat& operator=(const Cat& other);
		~Cat();
		//

		void	makeSound( void ) const;
};
