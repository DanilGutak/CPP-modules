
#include "WrongAnimal.hpp"

#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}
WrongAnimal::WrongAnimal( const WrongAnimal &other ) : _type(other._type) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}


WrongAnimal &WrongAnimal::operator=( const WrongAnimal &other ) {
	this->_type = other._type;
	std::cout << "WrongAnimal operator= called" << std::endl;
	return (*this);
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound" << std::endl;
}