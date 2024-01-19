/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:21 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/19 14:38:21 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef DOG_HPP
# define DOG_HPP


# include <string>
# include "Animal.hpp"

class Dog: public Animal{
public:
	Dog();
	Dog( const Dog &other );
	~Dog();
	void makeSound() const;
	Dog &operator=( const Dog &other );

};



#endif // DOG_HPP
