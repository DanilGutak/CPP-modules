/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:35:54 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/27 20:35:54 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef SPAN_HPP
# define SPAN_HPP


# include <string>
# include <iostream>
# include <vector>

class Span {
protected:
	const unsigned int	_N;
	std::vector<int>	_vec;


public:
	Span( const unsigned int N );
	Span( const Span &other );
	~Span();
	Span &operator=( const Span &other );
	unsigned int	getN() const;
	void addNumber(int num);
	void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan();
	int longestSpan();
};



#endif // SPAN_HPP
