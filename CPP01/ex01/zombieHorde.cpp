#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *squad = new(std::nothrow) Zombie[N];
    if (!squad)
    {
        std::cout << "alloc failed\n";
        return 0; 
    }
    for (int i = 0;i< N;i++)
    {
        squad[i].set_name(name);
        squad[i].announce();
    }
    return squad;
}