/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:49:45 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/21 14:49:45 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>


#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm",145,137){}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm",145,137), _target(target){}
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &other ) : AForm(0,145,137), _target(other._target){}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) {
	this->_target = other._target;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == 0)
		throw ShrubberyCreationForm::NotSignedException();
	if (executor.getGrade() > this->getGradexec())
		throw Bureaucrat::GradeTooLowException();
	std::ofstream file;
	file.open(this->_target + "_shrubbery");
	file << "     /\\      \n";
	file << "    /  \\     \n";
	file << "   /    \\    \n";
	file << "  /      \\   \n";
	file << " /        \\  \n";
	file << "/          \\ \n";
	file << "     /\\      \n";
	file << "    /  \\     \n";
	file << "   /    \\    \n";
	file << "  /      \\   \n";
	file << " /  TREE  \\  \n";
	file << "/          \\ \n";
	file << "     /\\      \n";
	file << "    /  \\     \n";
	file << "   /    \\    \n";
	file << "  /      \\   \n";
	file << " /        \\  \n";
	file << "/          \\ \n";
	file << "     /\\      \n";
	file << "    /  \\     \n";
	file << "    |||||     \n";





	file.close();
}


const char *ShrubberyCreationForm::NotSignedException::what( void) const throw() {
	return ("Form not signed");
}