/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:51:11 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/26 13:51:11 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>

Serializer::Serializer() {}
Serializer::Serializer( const Serializer & ) {}
Serializer::~Serializer() {}

Serializer &Serializer::operator=( const Serializer & ) {
	return (*this);
}

uintptr_t	Serializer::serialize( void *ptr ) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

void		*Serializer::deserialize( uintptr_t raw ) {
	return (reinterpret_cast<Data *>(raw));
}