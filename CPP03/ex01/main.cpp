#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
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

    {ScavTrap e("Catchy");
    ScavTrap f("Claw");
    ScavTrap g("Ceiling");
    ClapTrap *q = new ScavTrap("Cell");
    f.attack("dummy target");
    g.takeDamage(3);
    g.beRepaired(2);
    g.takeDamage(100);
    g.beRepaired(100);
    g.attack("dummy target");
    g.guardGate();
    q->attack("dummy target");
    delete q;
    }



}