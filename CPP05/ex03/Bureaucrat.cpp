/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:07:05 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/21 14:07:05 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"


Bureaucrat::Bureaucrat(){}
Bureaucrat::Bureaucrat(  const std::string name ,int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}
Bureaucrat::Bureaucrat( const Bureaucrat &other ) : _grade(other._grade), _name(other._name) {}
Bureaucrat::~Bureaucrat() {}

int Bureaucrat::getGrade( void ) const {
	return (this->_grade);
}
void Bureaucrat::signForm(AForm &form) {
	if (form.getSigned())
	{
		std::cout << this->_name << " cannot sign " << form.getName() << " because form is already signed\n";
		return ;
	}
	try {
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << '\n';
	}
	catch (std::exception &e) {
		std::cout << this->_name << " cannot sign " << form.getName() << " because " << e.what() << '\n';
	}
}
void Bureaucrat::incrementGrade( void ) {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}
void Bureaucrat::decrementGrade( void ) {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}
const std::string Bureaucrat::getName( void ) const {
	return (this->_name);
}
const char *Bureaucrat::GradeTooHighException::what( void) const throw() {
	return ("Grade too high");
}
const char *Bureaucrat::GradeTooLowException::what( void) const throw() {
	return ("Grade too low");
}
Bureaucrat &Bureaucrat::operator=( const Bureaucrat &other ) {
	this->_grade = other._grade;
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const Bureaucrat &instance ) {
	stream << instance.getName() << ','
		<< "bureacrat grade " << instance.getGrade() << '\n';
	return (stream);
}

void Bureaucrat::executeForm(AForm const & form) const{
	try {
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << '\n';
	}
	catch (std::exception &e) {
		std::cout << this->_name << " cannot execute " << form.getName() << " because " << e.what() << '\n';
	}
}