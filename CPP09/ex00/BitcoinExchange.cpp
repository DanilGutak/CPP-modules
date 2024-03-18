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
#include <cstring>
#include <cstdlib>

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
	
	std::ifstream check;
	check.open(filename.c_str());
	if (!check.is_open()) {
		throw InvalidFileException();
	}

	std::string checkstr;
	while (check.good()) {
		std::string buf;
		std::getline(check, buf);
		checkstr += buf + "\n";
	}
	std::string check2 = DATACSV;
	//check string char by char with DATACSV
	for (unsigned int i = 0; i < check2.length(); i++) {
		if (checkstr[i] != check2[i]) {
			throw InvalidFormatException();
		}
	}
	check.close();	
	std::ifstream inputFile;
    inputFile.open(filename.c_str());

    if (!inputFile.is_open()) {
		throw InvalidFileException();
    }
	std::string header;
	std::getline(inputFile, header);
	while (inputFile.good()) {
		std::string date;
		std::string price;
		std::getline(inputFile, date, ',');
		std::getline(inputFile, price);
		data[date] = strtod(price.c_str(), NULL);
	}
	inputFile.close();
	return data;
}

void BitcoinExchange::calculate(std::map<std::string, double> db, std::string filename) {
	std::ifstream inputFile;

    inputFile.open(filename.c_str());

	std::cout << std::fixed << std::setprecision(6);

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
		if (line.length() < 14) {
			std::cout << "Wrong date format" << "\n";
			continue;
		}
		//split line into date and value
		date = line.substr(0, 10);
		value = line.substr(13,line.length());
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
		int flag = 0;
		for (int i = 0; i < 10; i++) {
			if (i != 4 && i != 7 && !isdigit(date[i])) {
				std::cout << "Wrong date format" << "\n";
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			continue;
		// turn date into numbers
		int year = atoi(date.substr(0, 4).c_str());
		int month = atoi(date.substr(5, 2).c_str());
		int day = atoi(date.substr(8, 2).c_str());
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
		// february"   "<< counter
		if (month == 2 && day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))) {
			std::cout << "Wrong date format" << "\n";
			continue;
		// empty date
		}
		if (date == "") {
			std::cout << "Empty date" << "\n";
		}
		if (value == "") {
			std::cout << "Empty value" << "\n";
		}
		// check if value is a number
		int dots = 0;
		for (unsigned int i = 0; i < value.length(); i++) {
			if (!isdigit(value[i])) {
				if (value[i] == '.') {
					dots++;
					if (dots <= 1) {
						continue;
					}
					std::cout << "Wrong value format" <<value[i] <<"\n" ;
					flag = 1;
					break;
				}
				else
				{
					std::cout << "Wrong value format" <<value[i] <<"\n" ;
					flag = 1;
					break;
				}
			}
		}
		if (value == ".") {
			std::cout << "Wrong value format" << "\n";
			continue;
		}
		if (flag == 1)
			continue;
		valued = strtod(value.c_str(), NULL);
		// check if value is too big
		if (valued < 0 || valued > 1000) { 
			std::cout << "Wrong value format" << "\n";
			continue;
		}
		if (db.find(date) == db.end()) {
		std::map<std::string, double>::iterator iter = --db.lower_bound(date);
		std::cout << date << "=>" << valued << " = " <<  valued * iter->second << "\n";
		} else {
			std::cout << date << "=>" << valued << " = " << valued * db[date] << "\n";
		}
	}

	
	inputFile.close();
}