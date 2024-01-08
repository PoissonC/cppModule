/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:58:06 by ychen2            #+#    #+#             */
/*   Updated: 2024/01/08 21:53:34 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <sstream>
#include "Contact.hpp"

class	PhoneBook{
	public:
		PhoneBook();
		void	Search();
		void	NewContact();
		int		IsAvailable(int n);
	private:
		void	SearchPrint(int n);
		void	SearchPrintAll(int n);
		Contact contacts[8];
		int		next;
};

#endif