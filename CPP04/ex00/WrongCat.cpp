

#include "WrongCat.hpp"

#include <iostream>

WrongCat::WrongCat() {
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}
WrongCat::WrongCat( const WrongCat &other )  : WrongAnimal() {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = other;
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=( const WrongCat &other) {
	std::cout << "WrongCat operator= called" << std::endl;
	this->_type = other._type;
	return (*this);
}
void WrongCat::makeSound() const {
	std::cout << "Meow ^_^" << std::endl;
}
