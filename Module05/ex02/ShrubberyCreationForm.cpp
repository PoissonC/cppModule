/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychen2 <ychen2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 16:23:38 by yu                #+#    #+#             */
/*   Updated: 2024/03/03 22:50:22 by ychen2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : Form("shrubbery creation", target, 145, 137) {
	// std::cout << "Default constructor of ShrubberyCreationForm called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	// std::cout << "Destructor of ShrubberyCreationForm called" << std::endl;
}

void	ShrubberyCreationForm::action() const {
	std::ofstream file(this->getTarget().append("_shrubbery").c_str());
	if (file.is_open()) {
		file << "       _-_" << std::endl;
		file << "    /~~   ~~\\" << std::endl;
		file << " /~~         ~~\\" << std::endl;
		file << "{               }" << std::endl;
		file << " \\  _-     -_  /" << std::endl;
		file << "   ~  \\\\ //  ~" << std::endl;
		file << "_- -   | | _- _" << std::endl;
		file << "  _ -  | |   -_" << std::endl;
		file << "      // \\\\" << std::endl;

		file.close();
		std::cout << "ShrubberyCreationForm action called. ASCII tree written to " << this->getTarget() + "_shrubbery" << std::endl;
	}
	else {
		std::cerr << "Error: Could not open file for writing." << std::endl;
	}
}
