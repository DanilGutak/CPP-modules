/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:25 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/19 14:38:25 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef CAT_HPP
# define CAT_HPP


# include <string>
# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal {
private:
	Brain	*_brain;	
public:
	Cat();
	Cat( const Cat &other );
	~Cat();
	void makeSound() const;
	Cat &operator=( const Cat &other );
};

#endif // CAT_HPP
