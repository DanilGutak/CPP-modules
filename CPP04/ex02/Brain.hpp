/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 15:15:38 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/19 15:15:38 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP


# include <string>

class Brain {
private:
	std::string	ideas[100];
public:
	Brain();
	Brain( const Brain &other );
	~Brain();

	Brain &operator=( const Brain &other );
};

std::ostream	&operator<<( std::ostream &stream, const Brain &instance );


#endif // BRAIN_HPP
