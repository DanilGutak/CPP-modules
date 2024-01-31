/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:24:32 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/31 16:24:32 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include <iostream>

Intern::Intern() {}
Intern::Intern( const Intern & ) {}
Intern::~Intern() {}

Intern &Intern::operator=( const Intern & ) {
	return (*this);
}

AForm *Intern::makeForm( std::string formName, std::string target ) const {
	switch (formName[0]) {
		case 'r':
		{
			std::cout << "Intern creates RobotomyRequestForm" << std::endl;
			return (new RobotomyRequestForm(target));
		}
		case 'p':
		{
			std::cout << "Intern creates PresidentialPardonForm" << std::endl;
			return (new PresidentialPardonForm(target));

		}
		case 's':
		{
			std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
			return (new ShrubberyCreationForm(target));
		}
		default:
			std::cout << "Form not found" << std::endl;
			return (NULL);
	}
}