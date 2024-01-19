#include "FragTrap.hpp"

#include <iostream>

FragTrap::FragTrap() : ClapTrap()  {
	this->Name = "default";
	this->hp = 100;
	this->mp = 100;
	this->dmg = 30;
	std::cout << "FragTrap with default name " << " is born" << std::endl;
}
FragTrap::FragTrap(std::string Name) : ClapTrap() {
	this->Name = Name;
	this->hp = 100;
	this->mp = 100;
	this->dmg = 30;
	std::cout << "FragTrap with distinct name " << this->Name << " is born" << std::endl;
}
FragTrap::FragTrap( const FragTrap &other ) : ClapTrap(other) {
	std::cout << "FragTrap - " << this->Name << " was copied" << std::endl;
	*this = other;
}
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->Name << " is dead" << std::endl;
}

FragTrap &FragTrap::operator=( const FragTrap &other ) {
	this->Name = other.Name;
	this->hp = other.hp;
	this->mp = other.mp;
	this->dmg = other.dmg;
	std::cout << "FragTrap - " << this->Name << " was copied" << std::endl;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->Name << " needs to high five" << std::endl;
}