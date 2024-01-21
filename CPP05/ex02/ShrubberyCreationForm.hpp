
#pragma once

#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP


# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	Bureaucrat;

class ShrubberyCreationForm: public AForm {
private:
	std::string	_target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm( const std::string target);
	ShrubberyCreationForm( const ShrubberyCreationForm &other );
	~ShrubberyCreationForm();

	void execute(Bureaucrat const & executor) const;
	class NotSignedException: public std::exception {
		virtual const char* what() const throw();
	};


	ShrubberyCreationForm &operator=( const ShrubberyCreationForm &other );
};



#endif // ShrubberyCreationForm_HPP
