#include "Zombie.hpp"
int main(void)
{
    Zombie* squad =zombieHorde(5, "danil");
    delete [] squad;
}