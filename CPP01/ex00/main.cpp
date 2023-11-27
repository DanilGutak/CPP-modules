#include "Zombie.hpp"
#include <ostream>
int main(void)
{
    std::cout << "---------ZOMBIE 1------\n";
    Zombie zomb1;
    zomb1.announce();

    std::cout << "--------ZOMBIE 2----\n";
    Zombie zomb2("Petr");
    zomb2.announce();

    std::cout << "--------NEW ZOMBIE 3----\n";
    Zombie *zomb3 = newZombie("Danil");
    zomb3->announce();
    std::cout << "--------random CHUMP---\n";
    randomChump("Vitalik");
    std::cout << "--------Destructors----\n";
    delete zomb3;
}