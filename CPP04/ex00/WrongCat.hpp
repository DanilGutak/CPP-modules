/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:25 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/19 14:38:25 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef WrongCAT_HPP
# define WrongCAT_HPP


# include <string>
# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	WrongCat( const WrongCat &other );
	~WrongCat();
	void makeSound() const;
	WrongCat &operator=( const WrongCat &other );
};

#endif // WrongCAT_HPP
