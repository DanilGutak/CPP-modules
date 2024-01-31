/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:49:45 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/21 14:49:45 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"


#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm",72,45){}
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm",72,45), _target(target){}
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &other ) : AForm(0,72,45), _target(other._target){}
RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &other ) {
	this->_target = other._target;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == 0)
		throw RobotomyRequestForm::NotSignedException();
	if (executor.getGrade() > this->getGradexec())
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bzzz BZZz \n";
	if (rand() % 2)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " has not been robotomized." << std::endl; 
}

const char *RobotomyRequestForm::NotSignedException::what( void) const throw() {
	return ("Form not signed");
}