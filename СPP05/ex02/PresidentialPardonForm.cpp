/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:49:45 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/21 14:49:45 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"


#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm(0,25,5){}
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm(0,25,5), _target(target){}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &other ) : AForm(0,25,5), _target(other._target){}
PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &other ) {
	this->_target = other._target;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const {
	if (this->getSigned() == 0)
		throw PresidentialPardonForm::NotSignedException();
	if (executor.getGrade() > this->getGradexec())
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

const char *PresidentialPardonForm::NotSignedException::what( void) const throw() {
	return ("Form not signed");
}