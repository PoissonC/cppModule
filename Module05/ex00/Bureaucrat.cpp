/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:44:47 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string & name, int n) : _attr(new BureaucratImpl(name, n)) {
	if (this->_attr->_grade > 150) {
		delete this->_attr;
		throw GradeTooLowException();
	}
	else if (this->_attr->_grade < 1) {
		delete this->_attr;
		throw GradeTooHighException();
	}
}

Bureaucrat::BureaucratImpl::BureaucratImpl(const std::string & name, int n) : _name(name), _grade(n){
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _attr(new BureaucratImpl(other._attr->_name, other._attr->_grade)) {
}

void	Bureaucrat::swap(Bureaucrat &tar) {
	Bureaucrat::BureaucratImpl	*temp = this->_attr;
	this->_attr = tar._attr;
	tar._attr = temp;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat other) {
	this->swap(other);
	return *this;
}

Bureaucrat::~Bureaucrat() {
	delete this->_attr;
}

std::string	Bureaucrat::getName() const {
	return this->_attr->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_attr->_grade;
}

void Bureaucrat::incrementGrade() {
	if (this->_attr->_grade - 1 < 1)
		throw GradeTooHighException();
	else
		this->_attr->_grade--;
}

void Bureaucrat::decrementGrade() {
	if (this->_attr->_grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->_attr->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}
