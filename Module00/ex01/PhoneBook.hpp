/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:58:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/08 14:57:30 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook{
	public:
		PhoneBook();
		void	SearchPrint(int n);
		void	SearchPrintAll(int n);
		void	PrintContact(int n);
		void	NewContact();
		int		IsAvailable(int n);
	private:
		Contact contacts[8];
		int		next;
};

#endif