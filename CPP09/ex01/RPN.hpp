/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:24:31 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/02/01 15:24:31 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef RPN_HPP
# define RPN_HPP


# include <string>
# include <iostream>
# include <stack>
class RPN {
private:
	RPN();
	RPN( const RPN &other );
	~RPN();

	RPN &operator=( const RPN &other );
public:
	static std::string validate_input(std::string input);
	static int calculate(std::string input);

	class InvalidExpressionException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class NotEnoughValuesException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class DivisionByZeroException: public std::exception {
	public:
		virtual const char *what() const throw();
	};

};



#endif // RPN_HPP
