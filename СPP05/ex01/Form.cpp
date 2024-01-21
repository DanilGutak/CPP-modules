/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:49:45 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/21 14:49:45 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


#include <iostream>

void check_grade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}
Form::Form() :  _signed(0),  _gradesign(150), _gradexec(150){}
Form::Form( const std::string name,  const int gradesign, const int gradexec ) : _name(name), _signed(0), _gradesign(gradesign), _gradexec(gradexec) {
	check_grade(gradesign);
	check_grade(gradexec);
}
Form::Form( const Form &other ) : _name(other._name), _signed(other._signed), _gradesign(other._gradesign),  _gradexec(other._gradexec) {}
Form::~Form() {}

const std::string Form::getName( void ) const {
	return (this->_name);
}

void Form::beSigned( const Bureaucrat &bureaucrat ) {
	if (bureaucrat.getGrade() > this->_gradesign)
		throw Bureaucrat::GradeTooLowException();
	this->_signed = 1;
}

bool Form::getSigned( void ) const {
	return (this->_signed);
}

int Form::getGradesign( void ) const {
	return (this->_gradesign);
}
int Form::getGradexec( void ) const {
	return (this->_gradexec);
}
Form &Form::operator=( const Form &other ) {
	this->_signed = other._signed;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Form &instance ) {
	stream << "{Form:"
		<< "name=" << instance.getName() << ','
		<< "signed=" << instance.getSigned() << ','
		<< "grade=" << instance.getGradexec() << ','
		<< "grade=" << instance.getGradesign()<< "}\n";
	return (stream);
}
