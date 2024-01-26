/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:51:11 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/26 13:51:11 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP


# include <string>
# include <iostream>

class Serializer {
private:
	Serializer();
	Serializer( const Serializer &other );
	~Serializer();

	Serializer &operator=( const Serializer &other );
public:
	static uintptr_t	serialize( void *ptr );
	static void		*deserialize( uintptr_t raw );
};
struct Data {
	std::string	s1;
	int			n;
	std::string	s2;
};


#endif // SERIALIZER_HPP
