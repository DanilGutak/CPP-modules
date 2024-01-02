#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
    this->weapon = NULL;
}

void HumanB::attack()
{
    std::cout << this->name << " attacks with their " << ((this->weapon)? this->weapon->getType() : "fists");
    std::cout << "\n";
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}