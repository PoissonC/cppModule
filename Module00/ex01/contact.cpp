/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:09:22 by ychen2            #+#    #+#             */
/*   Updated: 2023/11/21 13:42:52 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void	Contact::inputName(){
	int	i;

	printf("Please input contact name: ");
	getline(&(this->name), &(this->name_len), stdin);
	if (!this->name)
		return ;
	i = -1;
	while (this->name[++i] != '\n');
	this->name[i] = '\0';
	this->name_len--;
}

void	Contact::inputNumber(){
	printf("Please input number: ");
	getline(&(this->number), &(this->number_len), stdin);
	if (!this->number)
		return ;
	for (int i = 0; number[i] != '\n'; i++) {
		if (isdigit(number[i]) == 0) {
			printf("it's me: %c\n",number[i]);
			this->deleteOne();
			break ;
		}
	}
}

void	Contact::deleteOne() {
	printf("One contact has been deleted.\n");
	if (this->name) {
		free(this->name);
		this->name = NULL;
	}
	if (this->number) {
		free(this->number);
		this->number = NULL;
	}
	this->name_len = 0;
	this->number_len = 0;
}

char*	Contact::getName(){
	return (this->name);
}

char*	Contact::getNumber(){
	return (this->number);
}

Contact::Contact(){
	this->name = NULL;
	this->name_len = 0;
	this->number = NULL;
	this->number_len = 0;
}

Contact::~Contact(){
	if (this->name) {
		free(this->name);
		this->name = NULL;
	}
	if (this->number) {
		free(this->number);
		this->number = NULL;
	}
}
