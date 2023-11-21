/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:58:06 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/21 13:37:11 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

class	Contact{
	public:
		Contact();
		~Contact();
		void	inputName();
		void	inputNumber();
		char*	getNumber();
		char*	getName();
		void	deleteOne();
	private:
		char	*name;
		size_t	name_len;
		char	*number;
		size_t	number_len;
};

class	PhoneBook{
	public:
		PhoneBook();
		char*	getPhoneNumber(int n);
		char*	getPhoneName(int n);
		void	newContact();
	private:
		Contact contacts[8];
		int		next;
};

class	PhoneBook;
#endif