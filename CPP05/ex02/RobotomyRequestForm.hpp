
#pragma once

#ifndef RobotomyRequestForm_HPP
# define RobotomyRequestForm_HPP


# include <string>
# include "Bureaucrat.hpp"
# include "AForm.hpp"

class	Bureaucrat;

class RobotomyRequestForm: public AForm {
private:
	std::string	_target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm( const std::string target);
	RobotomyRequestForm( const RobotomyRequestForm &other );
	~RobotomyRequestForm();

	void execute(Bureaucrat const & executor) const;
	class NotSignedException: public std::exception {
		virtual const char* what() const throw();
	};


	RobotomyRequestForm &operator=( const RobotomyRequestForm &other );
};



#endif // RobotomyRequestForm_HPP
