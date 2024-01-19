#include "ScavTrap.hpp"

#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()  {
	this->Name = "default";
	this->hp = 100;
	this->mp = 50;
	this->dmg = 20;
	std::cout << "ScavTrap with default name " << " is born" << std::endl;
}
ScavTrap::ScavTrap(std::string Name) : ClapTrap() {
	this->Name = Name;
	this->hp = 100;
	this->mp = 50;
	this->dmg = 20;
	std::cout << "ScavTrap with distinct name " << this->Name << " is born" << std::endl;
}
ScavTrap::ScavTrap( const ScavTrap &other ) : ClapTrap(other) {
	std::cout << "ScavTrap - " << this->Name << " was copied" << std::endl;
	*this = other;

}
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->Name << " is dead" << std::endl;
}

ScavTrap &ScavTrap::operator=( const ScavTrap &other ) {
	this->Name = other.Name;
	this->hp = other.hp;
	this->mp = other.mp;
	this->dmg = other.dmg;
	std::cout << "ScavTrap - " << this->Name << " was copied" << std::endl;
	return (*this);
}
void ScavTrap::attack(const std::string& target)
{
	if (this->hp <= 0)
	{
		std::cout << "ScavTrap " << this->Name << " is dead and cannot do anything" << std::endl;
		return ;
	}
	if (this->mp <= 0)
	{
		std::cout << "ScavTrap " << this->Name << " is out of mana and cannot do anything" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
	this->mp -= 1;
}
void ScavTrap::guardGate()
{
	if (this->hp <= 0)
	{
		std::cout << "ScavTrap " << this->Name << " is dead and cannot do anything" << std::endl;
		return ;
	}
	if (this->mp <= 0)
	{
		std::cout << "ScavTrap " << this->Name << " is out of mana and cannot do anything" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->Name << " has enterred in Gate keeper mode" << std::endl;
}