/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:58:06 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/21 16:35:10 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

class	Contact{
	public:
		Contact();
		int		InputInfo();
		void	Print();
		int		IsAvailable();
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;
		std::string	darkest_secret;
		int		available;
};

class	PhoneBook{
	public:
		PhoneBook();
		void	PrintContact(int n);
		void	NewContact();
		int		IsAvailable(int n);
	private:
		Contact contacts[8];
		int		next;
};

#endif