#include <iostream>
#include "ClapTrap.hpp"
int main( void ) {
    ClapTrap a("ClapTrap");
    ClapTrap b("ClapTrap");
    ClapTrap c("ClapTrap");
    ClapTrap d("ClapTrap");

    b.attack("dummy target");
    c.takeDamage(3);
    c.beRepaired(2);
    d.takeDamage(100);
    d.beRepaired(100);
    d.attack("dummy target");

}