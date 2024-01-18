#include "ClapTrap.hpp"

#include <iostream>

ClapTrap::ClapTrap() : Name("default"), hp(10), mp(10), dmg(0) {
	std::cout << "ClapTrap with default name " << " is born" << std::endl;
}
ClapTrap::ClapTrap(std::string Name) : Name(Name), hp(10), mp(10), dmg(0) {
	std::cout << "ClapTrap with distinct name - " << this->Name << " is born" << std::endl;
}
ClapTrap::ClapTrap( const ClapTrap &other ) : Name(other.Name), hp(other.hp), mp(other.mp), dmg(other.dmg) {
	std::cout << "ClapTrap - " << this->Name << " was copied" << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->Name << " is dead" << std::endl;
}

ClapTrap &ClapTrap::operator=( const ClapTrap &other ) {
	this->Name = other.Name;
	this->hp = other.hp;
	this->mp = other.mp;
	this->dmg = other.dmg;
	std::cout << "ClapTrap - " << this->Name << " was copied" << std::endl;
	return (*this);
}
void ClapTrap::attack(const std::string& target)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead and cannot do anything" << std::endl;
		return ;
	}
	if (this->mp <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " is out of mana and cannot do anything" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
	this->mp -= 1;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if ( this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead and cannot do anything" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " takes " << amount << " points of damage!" << std::endl;
	this->hp -= amount;

}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " is dead and cannot do anything" << std::endl;
		return ;
	}
	if (this->mp <= 0)
	{
		std::cout << "ClapTrap " << this->Name << " is out of mana and cannot do anything" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->Name << " beRepaired " << amount << " points of damage!" << std::endl;
	this->hp += amount;
	this->mp -= 1;
}