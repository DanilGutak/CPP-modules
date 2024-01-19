/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:21 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/19 14:38:21 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

#include <iostream>

Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog( const Dog &other) : Animal() {
	std::cout << "Dog copy constructor called" << std::endl;
 	*this = other;

}
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=( const Dog &other ) {
	std::cout << "Dog operator= called" << std::endl;
	this->_type = other._type;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof Woof (|)0_o(|)" << std::endl;
}
