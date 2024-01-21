
#pragma once

#ifndef FORM_HPP
# define FORM_HPP


# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class Form {
protected:
	const std::string	_name;
	bool	_signed;
	const int	_gradesign;
	const int _gradexec;

public:
	Form();
	Form( const std::string name,  const int gradesign, const int gradexec );
	Form( const Form &other );
	~Form();

	const	std::string	getName( void ) const;
	bool	getSigned( void ) const;
	int	getGradesign( void ) const;
	int	getGradexec( void ) const;
	void	beSigned( const Bureaucrat &bureaucrat );



	Form &operator=( const Form &other );
};

std::ostream	&operator<<( std::ostream &stream, const Form &instance );


#endif // FORM_HPP
