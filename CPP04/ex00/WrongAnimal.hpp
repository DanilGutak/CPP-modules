
#pragma once

#ifndef WrongANIMAL_HPP
# define WrongANIMAL_HPP


# include <string>


class WrongAnimal {
protected:
	std::string	_type;

public:
	WrongAnimal();
	WrongAnimal( const WrongAnimal &other );
	virtual ~WrongAnimal();

	void makeSound() const;

	WrongAnimal &operator=( const WrongAnimal &other );
};

std::ostream	&operator<<( std::ostream &stream, const WrongAnimal &instance );


#endif // WrongANIMAL_HPP
