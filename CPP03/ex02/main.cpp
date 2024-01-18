#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
int main( void ) {
    {ClapTrap a;
    ClapTrap b("ClapTrap2");
    ClapTrap c("ClapTrap3");
    ClapTrap d("ClapTrap4");


    b.attack("dummy target");
    c.takeDamage(3);
    c.beRepaired(2);
    d.takeDamage(100);
    d.beRepaired(100);
    d.attack("dummy target");}


    {
        FragTrap h("FragTrap");
        FragTrap i("FragTrap2");
        FragTrap j("FragTrap3");
        FragTrap k("FragTrap4");

        i.attack("dummy target");
        j.takeDamage(3);
        j.beRepaired(2);
        k.takeDamage(100);
        k.beRepaired(100);
        k.attack("dummy target");
        k.highFivesGuys();
    }


}