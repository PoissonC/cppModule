/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yu <yu@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:58:06 by ychen2            #+#    #+#             */
/*   Updated: 2023/12/04 20:47:36 by yu               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

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