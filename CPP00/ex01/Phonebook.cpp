#include "Phonebook.hpp"
#include <iostream>

void Phonebook::add(int i)
{
	std::string input = "";
	while (input.empty() == 1)
	{
		std::cout << "First_Name :";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
	}
	this->contacts[i].set_first_name(input);
	input = "";

	while (input.empty() == 1)
	{
		std::cout << "Last_Name :";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
	}
	this->contacts[i].set_last_name(input);
	input = "";

	while (input.empty() == 1)
	{
		std::cout << "Nickname :";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
	}
	this->contacts[i].set_nickname(input);
	input = "";

	while (input.empty() == 1)
	{
		std::cout << "Number :";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
	}
	this->contacts[i].set_number(input);
	input = "";

	while (input.empty() == 1)
	{
		std::cout << "Darkest_secret :";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
	}
	this->contacts[i].set_darkest_secret(input);
	input = "";
}

void Phonebook::search(void)
{
	std::string input;
	for (int i = 0; i < 8; i++)
	{
		std::string first_name = this->contacts[i].get_first_name();
		std::string last_name = this->contacts[i].get_last_name();
		std::string nickname = this->contacts[i].get_nickname();
		std::string number = this->contacts[i].get_number();
		if (first_name.length() > 9)
		{
			first_name = first_name.replace(9, 1, ".");
			first_name.resize(10, ' ');
		}
		if (last_name.length() > 9)
		{
			last_name = last_name.replace(9, 1, ".");
			last_name.resize(10, ' ');
		}
		if (nickname.length() > 9)
		{
			nickname = nickname.replace(9, 1, ".");
			nickname.resize(10, ' ');
		}
		if (number.length() > 9)
		{
			number = number.replace(9, 1, ".");
			number.resize(10, ' ');
		}
		std::cout << "|" << std::setw(10) << std::right << first_name << "|";
		std::cout << std::setw(10) << std::right << last_name << "|";
		std::cout << std::setw(10) << std::right << nickname << "|";
		std::cout << std::setw(10) << std::right << number << "|\n";
	}
	while (1)
	{
		std::cout << "Type your INDEX: ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			return ;
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
		{
			std::cout << "First_Name: " << this->contacts[input[0]
				- '0'].get_first_name() << "\n";
			std::cout << "Last_Name: " << this->contacts[input[0]
				- '0'].get_last_name() << "\n";
			std::cout << "Nickname: " << this->contacts[input[0]
				- '0'].get_nickname() << "\n";
			std::cout << "Number: " << this->contacts[input[0]
				- '0'].get_number() << "\n";
			std::cout << "Darkest_secret: " << this->contacts[input[0]
				- '0'].get_darkest_secret() << "\n";
			return ;
		}
		std::cout << "Not a correct index try again!\n";
	}
}