#include "Phonebook.hpp"

void Phonebook::add(int i)
{
	std::string input;

	std::cout << "First_Name :";
	std::getline(std::cin, input);
	this->contacts[i].set_first_name(input);
	std::cout << "Last_Name :";
	std::getline(std::cin, input);
	this->contacts[i].set_last_name(input);

	std::cout << "Nickname :";
	std::getline(std::cin, input);
	this->contacts[i].set_nickname(input);

	std::cout << "Number :";
	std::getline(std::cin, input);
	this->contacts[i].set_number(input);

	std::cout << "Darkest_secret :";
	std::getline(std::cin, input);
	this->contacts[i].set_darkest_secret(input);
}

void Phonebook::search(void)
{
	for (int i = 0; i < 8; i++)
	{
        std::cout << "|" << std::setw(10) << std::right<< this->contacts[i].get_first_name() << "|";
		std::cout << std::setw(10) << std::right << this->contacts[i].get_last_name() << "|";
        std::cout << std::setw(10)<< std::right << this->contacts[i].get_nickname() << "|";
        std::cout << std::setw(10) << std::right << this->contacts[i].get_number() << "|"n";
	}
}