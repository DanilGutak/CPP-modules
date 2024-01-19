
#pragma once

#ifndef ANIMAL_HPP
# define ANIMAL_HPP


# include <string>


class Animal {
protected:
	std::string	_type;

public:
	Animal();
	Animal( const Animal &other );
	virtual ~Animal();

	virtual void makeSound() const = 0;
	std::string getType() const;

	Animal &operator=( const Animal &other );
};

std::ostream	&operator<<( std::ostream &stream, const Animal &instance );


#endif // ANIMAL_HPP
