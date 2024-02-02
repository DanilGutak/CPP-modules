/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:52:57 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/02/01 17:52:57 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange( const BitcoinExchange & ) {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=( const BitcoinExchange & ) {
	return (*this);
}

std::ostream	&operator<<( std::ostream &stream, const BitcoinExchange & ) {
	stream << "{BitcoinExchange:{}}";
	return (stream);
}
const char *BitcoinExchange::InvalidFileException::what() const throw() {
	return ("Invalid file");
}
const char *BitcoinExchange::InvalidFormatException::what() const throw() {
	return ("Invalid format");
}

std::map<std::string, double> BitcoinExchange::readdb(std::string filename) {
	std::map<std::string, double> data;
	
	std::ifstream inputFile;

    inputFile.open(filename);

    if (!inputFile.is_open()) {
		throw InvalidFileException();
    }
	std::string header;
	std::getline(inputFile, header);
	if (header != "date,exchange_rate") {
		throw InvalidFormatException();
	}
	while (inputFile.good()) {
		std::string date;
		std::string price;
		std::getline(inputFile, date, ',');
		std::getline(inputFile, price);
		if (date == "" || price == "") {
			break;
		}
		data[date] = std::stod(price);
	}
	inputFile.close();
	for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++) {
		if (it->second < 0) {
			throw InvalidFormatException();
		}
		if (it->first.length() != 10) {
			throw InvalidFormatException();
		}

		if (it->first[4] != '-' || it->first[7] != '-') {
			throw InvalidFormatException();
		}

		for (int i = 0; i < 10; i++) {
			if (i != 4 && i != 7 && !isdigit(it->first[i])) {
				throw InvalidFormatException();
			}
		}
		int year = std::stoi(it->first.substr(0, 4));
		int month = std::stoi(it->first.substr(5, 2));
		int day = std::stoi(it->first.substr(8, 2));
		if (month < 1 || month > 12 || day < 1 || day > 31) {
			throw InvalidFormatException();
		}
		if (month == 2 && day > 29) {
			throw InvalidFormatException();
		}
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			throw InvalidFormatException();
		}
		if (month == 2 && day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {
			throw InvalidFormatException();
		}
	}
	return data;
}

void BitcoinExchange::calculate(std::map<std::string, double> db, std::string filename) {
	std::ifstream inputFile;

    inputFile.open(filename);

    if (!inputFile.is_open()) {
		throw InvalidFileException();
    }
	std::string header;
	std::getline(inputFile, header);
	if (header != "date | value") {
		throw InvalidFormatException();
	}
	while (inputFile.good()) {
		std::string date;
		std::string value;
		std::string line;
		double valued;
		std::getline(inputFile, line );
		//split line into date and value
		date = line.substr(0, 10);
		value = line.substr(13,line.length());
		std::cout << date<< "  "<< value << "\n";
		// check length
		if (date.length() != 10) {
			std::cout << "Wrong date format" << "\n";
			continue;
		}
		// check "-" in "YYYY-MM-DD"
		if (date[4] != '-' || date[7] != '-') {
			std::cout << "Wrong date format" << "\n";
			continue;

		}
		//check that date is a number
		for (int i = 0; i < 10; i++) {
			if (i != 4 && i != 7 && !isdigit(date[i])) {
				std::cout << "Wrong date format" << "\n";
				continue;
			}
		}
		// turn date into numbers
		int year = std::stoi(date.substr(0, 4));
		int month = std::stoi(date.substr(5, 2));
		int day = std::stoi(date.substr(8, 2));
		// check if date is valid
		if (month < 1 || month > 12 || day < 1 || day > 31) {
			std::cout << "Wrong date format" << "\n";
			continue;

		}
		// 29 days month
		if (month == 2 && day > 29) {
			std::cout << "Wrong date format" << "\n";
			continue;

		}
		// 30 days months
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			std::cout << "Wrong date format" << "\n";
			continue;
		}
		// february
		if (month == 2 && day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {
			std::cout << "Wrong date format" << "\n";
			continue;
		// empty date
		}
		if (date == "") {
			std::cout << "Empty date" << "\n";
		}
		std::getline(inputFile, value);
		if (value == "") {
			std::cout << "Empty value" << "\n";
		}
		// check if value is a number
		for (unsigned int i = 1; i < value.length(); i++) {
			if (!isdigit(value[i]) && value[i] != '.') {
				std::cout << "Wrong value format" << "\n";
				value = "";
				break;
			}
		}
		if (value == "")
			continue;
		valued = std::stod(value);
		// check if value is too big
		if (valued > 2147483647) {
			std::cout << "Wrong value format" << "\n";
			continue;
		}
		if (db.find(date) == db.end()) {
		std::map<std::string, double>::iterator iter = db.lower_bound(date);
		std::cout << date << "=>" << valued << " = " <<  valued * iter->second << "\n";
		} else {
			std::cout << date << " = >" << valued << " = " << valued * db[date] << "\n";
		}
	}

	
	inputFile.close();
}