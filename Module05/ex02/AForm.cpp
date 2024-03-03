/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:12:06 by yu                #+#    #+#             */
/*   Updated: 2024/01/14 19:44:47 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string & name, int sign, int exe) : _attr(new AFormImpl(name, sign, exe)) {
	std::cout << "Default constructor of basic form called" << std::endl;
	if (sign > 150 || exe > 150) {
		delete this->_attr;
		throw GradeTooLowException();
	}
	else if (sign < 1 || exe < 1) {
		delete this->_attr;
		throw GradeTooHighException();
	}
}

AForm::AFormImpl::AFormImpl(const std::string & name, int sign, int exe) : _name(name), _signeRequiredGrade(sign), _executeRequiredGrade(exe) {
	this->_isSigned = false;
}

AForm::AForm(const AForm& other) : _attr(new AFormImpl(other._attr->_name, other._attr->_signeRequiredGrade, other._attr->_executeRequiredGrade)) {
	std::cout << "Copy constructor of basic form called" << std::endl;
	this->_attr->_isSigned = other._attr->_isSigned;
}

void	AForm::swap(AForm &tar) {
	AForm::AFormImpl	*temp = this->_attr;
	this->_attr = tar._attr;
	tar._attr = temp;
}

AForm&	AForm::operator=(AForm other) {
	std::cout << "Copy assignment operator of basic form called" << std::endl;
	this->swap(other);
	return *this;
}

AForm::~AForm() {
	delete this->_attr;
}

std::string	AForm::getName() const {
	return this->_attr->_name;
}

bool	AForm::getIsSigned() const {
	return this->_attr->_isSigned;
}

int		AForm::getSigneRequiredGrade() const {
	return this->_attr->_signeRequiredGrade;
}

int		AForm::getExecuteRequiredGrade() const {
	return this->_attr->_executeRequiredGrade;
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form name: "<< form.getName() << std::endl;
	if (form.getIsSigned())
		os << "The form is signed." << std::endl;
	else
		os << "The form is not signed yet." << std::endl;
	os << "Required Grade to sign the form: " << form.getSigneRequiredGrade() << std::endl;
	os << "Required Grade to execute the form: " << form.getExecuteRequiredGrade() << std::endl;
    return os;
}

void	AForm::beSigned(Bureaucrat & bureaucrat) {
	if (bureaucrat.signForm(*this))
		this->_attr->_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->_attr->_executeRequiredGrade)
		throw GradeTooLowException();
	else if (!this->_attr->_isSigned) {
		throw NotSigned();
	}
	std::cout << executor.getName() << " executes " << this->getName() << std::endl;
	this->action();
}

void	AForm::action() const {
	throw UnDefined();
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

const char* AForm::UnDefined::what() const throw() {
	return "The behavior of the form is not defined.";
}

const char* AForm::NotSigned::what() const throw() {
	return "The form is not signed yet, thus it cannot be executed.";
}