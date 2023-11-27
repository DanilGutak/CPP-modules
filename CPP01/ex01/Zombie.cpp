#include "Zombie.hpp"

Zombie::Zombie(void)
{

}
Zombie::Zombie(std::string name) : name(name)
{

}
Zombie::~Zombie(void)
{
    std::cout << this->name << ": me double dead:(\n";
}
void Zombie::announce(void)
{
    std::cout << this->name<< ": BraiiiiiiinnnzzzZ...\n";

}
void Zombie::set_name(std::string name)
{
    this->name = name;
}
