#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *squad = new Zombie[N];
    for (int i = 0;i< N;i++)
    {
        squad[i] = Zombie(name);
        squad[i].announce();
    }
    return squad;
}