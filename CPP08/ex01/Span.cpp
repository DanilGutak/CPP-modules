/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:35:54 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/27 20:35:54 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


Span::Span( const unsigned int N ) : _N(N) {}
Span::Span( const Span &other ) : _N(other._N) {}
Span::~Span() {}



Span &Span::operator=( const Span &other ) {
	this->_vec = other._vec;
	return (*this);
}

unsigned int	Span::getN() const {
	return (this->_N);
}

int Span::longestSpan()
{
	if (this->_vec.size() < 2)
		throw std::exception();
	std::vector<int>::iterator min = std::min_element(this->_vec.begin(), this->_vec.end());
	std::vector<int>::iterator max = std::max_element(this->_vec.begin(), this->_vec.end());
	return (*max - *min);
}
int Span::shortestSpan()
{
	if (this->_vec.size() < 2)
		throw std::exception();
	int shortestSpan = INT_MAX;
	std::vector<int>::iterator it = this->_vec.begin();
	std::vector<int>::iterator itend = this->_vec.end();
	std::vector<int>::iterator it2 = it + 1;
	while (it != itend)
	{
		while (it2 != itend)
		{
			if (std::abs(*it - *it2) < shortestSpan)
				shortestSpan = std::abs(*it - *it2);
			it2++;
		}
		it++;
		it2 = it + 1;
	}
	return (shortestSpan);
}

void Span::addNumber(int num)
{
	if (this->_vec.size() == this->_N)
		throw std::exception();
	this->_vec.push_back(num);
}
void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_vec.size() + std::distance(begin, end) > this->_N)
		throw std::exception();
	this->_vec.insert(this->_vec.end(), begin, end);
}
