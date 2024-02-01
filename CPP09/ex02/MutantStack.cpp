/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:14:25 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/31 15:14:25 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

#include <iostream>

MutantStack::MutantStack() {}
MutantStack::MutantStack( const MutantStack & ) {}
MutantStack::~MutantStack() {}

MutantStack &MutantStack::operator=( const MutantStack & ) {
	return (*this);
}