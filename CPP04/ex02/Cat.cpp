#include "Cat.hpp"

#include <iostream>

Cat::Cat(): Animal(), _brain(new Brain) {
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat( const Cat &other): Animal(), _brain(new Brain) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}
Cat::~Cat() {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=( const Cat &other) {
	std::cout << "Cat operator= called" << std::endl;
	this->_type = other._type;
	*this->_brain = *other._brain;
	return (*this);
}
void Cat::makeSound() const {
	std::cout << "Meow ^_^" << std::endl;
}
