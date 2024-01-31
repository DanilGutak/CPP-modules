
#pragma once

#ifndef AFORM_HPP
# define AFORM_HPP


# include <string>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool	_signed;
	const int	_gradesign;
	const int _gradexec;

public:
	AForm();
	AForm( const std::string name,  const int gradesign, const int gradexec );
	AForm( const AForm &other );
	virtual ~AForm();

	const	std::string	getName( void ) const;
	bool	getSigned( void ) const;
	int	getGradesign( void ) const;
	int	getGradexec( void ) const;
	void	beSigned( const Bureaucrat &bureaucrat );
	virtual void execute(Bureaucrat const & executor) const = 0;



	AForm &operator=( const AForm &other );
};

std::ostream	&operator<<( std::ostream &stream, const AForm &instance );


#endif // AFORM_HPP
