/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:09:22 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/20 18:26:47 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

class	Contact{
	public:
		Contact();
		void	inputName();
		void	getNumber();
	private:
		char	*name;
		size_t	name_len;
		char	*number;
		size_t	number_len;
};

void	Contact::inputName(){
	getline(&name, &name_len, stdin);
}

void	getNumber(){
	getline(&number, &number_len, stdin);
}

Contact::Contact(){
	name = NULL;
	name_len = 0;
}
