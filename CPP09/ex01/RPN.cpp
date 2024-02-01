/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:24:31 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/02/01 15:24:31 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#include <iostream>

RPN::RPN() {}
RPN::RPN( const RPN & ) {}
RPN::~RPN() {}

RPN &RPN::operator=( const RPN & ) {
	return (*this);
}

const char * RPN::InvalidExpressionException::what() const throw() {
	return "Wrong experessionsyntax";
}
const char * RPN::NotEnoughValuesException::what() const throw() {
	return "Not enough values";
}
const char * RPN::DivisionByZeroException::what() const throw() {
	return "Division by zero";
}
std::string RPN::validate_input(std::string input) {
	std::string str;
	int i = 0;
	int length = input.length(); 
	while (i < length) {
		if (i % 2 == 0 && !isdigit(input.at(i)) && input.at(i) != '+' && input.at(i) != '-' && input.at(i) != '*' && input.at(i) != '/' )
			throw RPN::InvalidExpressionException();
		else if (i % 2 == 1 && input.at(i) != ' '&& i != length - 1)
			throw RPN::InvalidExpressionException();
		if (input.at(i) != ' ')
			str += input.at(i);
		i++;
	}
	return str;
}
int RPN::calculate(std::string input)
{
	std::stack<double> stack;
	std::string str = validate_input(input);
	int i = 0;
	int length = str.length();
	while (i < length)
	{
		if (isdigit(input.at(i)))
		{
			stack.push(std::atoi(&input.at(i)));
		}
		if (input.at(i) == '+')
		{
			if (stack.size() < 2)
				throw RPN::NotEnoughValuesException();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(a + b);
			std::cout << a << " + " << b << " = " << a + b << std::endl;
		}
		else if (input.at(i) == '-')
		{
			if (stack.size() < 2)
				throw RPN::NotEnoughValuesException();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(b - a);
		}
		else if (input.at(i) == '*')
		{
			if (stack.size() < 2)
				throw RPN::NotEnoughValuesException();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(a * b);
		}
		else if (input.at(i) == '/')
		{
			if (stack.size() < 2)
				throw RPN::NotEnoughValuesException();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			if (a == 0)
				throw RPN::DivisionByZeroException();
			stack.push(b / a);
		}
		i++;
	}
	return stack.top();

}