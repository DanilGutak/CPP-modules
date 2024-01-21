
#pragma once

#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP


# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	Bureaucrat;

class PresidentialPardonForm: public AForm {
private:
	std::string	_target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm( const std::string target);
	PresidentialPardonForm( const PresidentialPardonForm &other );
	~PresidentialPardonForm();

	void execute(Bureaucrat const & executor) const;
	class NotSignedException: public std::exception {
		virtual const char* what() const throw();
	};


	PresidentialPardonForm &operator=( const PresidentialPardonForm &other );
};



#endif // PresidentialPardonForm_HPP
