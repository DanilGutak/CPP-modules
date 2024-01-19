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

Dog::Dog() : Animal(), _brain(new Brain()) {
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}
Dog::Dog( const Dog & ) : Animal(), _brain(new Brain()){
	std::cout << "Dog copy constructor called" << std::endl;
}
Dog::~Dog() {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=( const Dog & ) {
	std::cout << "Dog operator= called" << std::endl;
	return (*this);
}

void Dog::makeSound() const {
	std::cout << "Woof Woof (|)0_o(|)" << std::endl;
}
