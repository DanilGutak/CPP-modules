/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:52:57 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/02/01 17:52:57 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP


# include <string>
# include <iostream>
# include <map>


class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange( const BitcoinExchange &other );
	~BitcoinExchange();

	BitcoinExchange &operator=( const BitcoinExchange &other );
	static std::map<std::string, double> readdb(std::string filename);
	static void validate(std::map<std::string, double>);
	static void calculate(std::map<std::string, double> data, std::string filename);

	class InvalidFileException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
	class InvalidFormatException: public std::exception {
	public:
		virtual const char *what() const throw();
	};
};

std::ostream	&operator<<( std::ostream &stream, const BitcoinExchange &instance );


#endif // BITCOIN_EXCHANGE_HPP
