
#include "Animal.hpp"

#include <iostream>

Animal::Animal() : _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}
Animal::Animal( const Animal &other ) : _type(other._type) {
	std::cout << "Animal copy constructor called" << std::endl;
}
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}


Animal &Animal::operator=( const Animal &other ) {
	this->_type = other._type;
	std::cout << "Animal operator= called" << std::endl;
	return (*this);
}

std::string Animal::getType() const {
	return (this->_type);
}

