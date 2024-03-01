/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:46:15 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:34:45 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class	Bureaucrat{
	public:
		// OCF
		Bureaucrat();
		Bureaucrat(const std::string & name, int n);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(Bureaucrat other);
		virtual ~Bureaucrat();
		//
		
		// getters
		std::string	getName();
		int			getGrade();
		//

		// Member funcs
		void		incrementGrade();
		void		decrementGrade();
		//

		// Utils
		void		swap(Bureaucrat &tar);
		//

		// Exceptions
		class	GradeTooHighException : public std::exception {
			public:
        		virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception {
			public:
        		virtual const char* what() const throw();
		};
		//
	private:
		class			BureaucratImpl;
		BureaucratImpl	*_attr;
};

class Bureaucrat::BureaucratImpl {
	public:
		//constructors
		BureaucratImpl(const std::string & name, int n);

		//attributes
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);