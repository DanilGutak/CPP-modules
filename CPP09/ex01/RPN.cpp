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
	return "Wrong Experession Syntax";
}
const char * RPN::NotEnoughValuesException::what() const throw() {
	return "Not Enough Values";
}
const char * RPN::DivisionByZeroException::what() const throw() {
	return "Division By Zero";
}
std::string RPN::validate_input(std::string input) {
	std::string str;
	int i = 0;
	int num = 0;
	int ops = 0;
	int length = input.length(); 
	while (i < length) {
		if (i % 2 == 0 && !isdigit(input.at(i)) && input.at(i) != '+' && input.at(i) != '-' && input.at(i) != '*' && input.at(i) != '/' )
			throw RPN::InvalidExpressionException();
		else if (i % 2 == 1 && input.at(i) != ' '&& i != length - 1)
			throw RPN::InvalidExpressionException();
		if (input.at(i) != ' ')
		{
			str += input.at(i);
			if (std::isdigit(input[i]))
				num++;
			else
				ops++;
		}
		i++;
	}
	if (num - ops != 1)
		throw RPN::InvalidExpressionException();
	return str;
}
double RPN::calculate(std::string input)
{
	std::stack<double> stack;
	std::string str = validate_input(input);
	double i = 0;
	double length = str.length();
	while (i < length)
	{
		if (isdigit(str[i]))
		{
			double digit = static_cast<double>(str[i] - '0'); 
   			stack.push(digit);
		}
		if (str.at(i) == '+')
		{
			if (stack.size() < 2)
				throw RPN::NotEnoughValuesException();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(a + b);
		}
		else if (str.at(i) == '-')
		{
			if (stack.size() < 2)
				throw RPN::NotEnoughValuesException();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(b - a);
		}
		else if (str.at(i) == '*')
		{
			if (stack.size() < 2)
				throw RPN::NotEnoughValuesException();
			double a = stack.top();
			stack.pop();
			double b = stack.top();
			stack.pop();
			stack.push(a * b);
		}
		else if (str.at(i) == '/')
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
	return (stack.top());

}