#include "Zombie.hpp"
#include <ostream>
int main(void)
{
    Zombie* squad =zombieHorde(5, "danil");
    delete [] squad;
}