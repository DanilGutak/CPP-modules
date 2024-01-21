/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:07:05 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/21 14:07:05 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


# include <string>
# include <iostream>
#include "AForm.hpp"

class	AForm;
class Bureaucrat {
private:
	int	_grade;
	const std::string	_name;

public:
	Bureaucrat();
	Bureaucrat(  const std::string name, int grade);
	Bureaucrat( const Bureaucrat &other );
	~Bureaucrat();

	int			getGrade( void ) const;
	const std::string	getName( void ) const;
	void 		incrementGrade( void );
	void 		decrementGrade( void );
	class GradeTooHighException : public std::exception {
	public:
		const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public:
		const char *what() const throw();
	};
	void signForm(AForm &form);
	void executeForm(AForm const & form) const;
	Bureaucrat &operator=( const Bureaucrat &other );
};

std::ostream	&operator<<( std::ostream &stream, const Bureaucrat &instance );


#endif // BUREAUCRAT_HPP
