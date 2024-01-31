/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:49:45 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/21 14:49:45 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


#include <iostream>

void check_grade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
AForm::AForm() : _name("default"), _signed(0),  _gradesign(150), _gradexec(150){}
AForm::AForm( const std::string name,  const int gradesign, const int gradexec ) : _name(name), _signed(0), _gradesign(gradesign), _gradexec(gradexec) {
	check_grade(gradesign);
	check_grade(gradexec);
}
AForm::AForm( const AForm &other ) : _name(other._name), _signed(other._signed), _gradesign(other._gradesign),  _gradexec(other._gradexec) {}
AForm::~AForm() {}

const std::string AForm::getName( void ) const {
	return (this->_name);
}

void AForm::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > this->_gradesign)
		throw Bureaucrat::GradeTooLowException();
	this->_signed = 1;
}

bool AForm::getSigned( void ) const {
	return (this->_signed);
}

int AForm::getGradesign( void ) const {
	return (this->_gradesign);
}
int AForm::getGradexec( void ) const {
	return (this->_gradexec);
}
AForm &AForm::operator=( const AForm &other ) {
	this->_signed = other._signed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const AForm &instance ) {
	stream << "{AForm:"
		<< "name=" << instance.getName() << ','
		<< "signed=" << instance.getSigned() << ','
		<< "gradexec=" << instance.getGradexec() << ','
		<< "gradesign=" << instance.getGradesign()<< "}\n";
	return (stream);
}
