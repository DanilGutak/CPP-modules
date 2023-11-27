

# include <iostream>
class Zombie
{
    
    public:
        void announce( void );
        Zombie();
        Zombie(std::string name);
        ~Zombie();
    private:
        std::string name;
};
Zombie* zombieHorde( int N, std::string name );