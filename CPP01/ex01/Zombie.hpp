

# include <iostream>
class Zombie
{
    
    public:
        void announce( void );
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void set_name(std::string name);
    private:
        std::string name;
};
Zombie* zombieHorde( int N, std::string name );