

# include <iostream>
class Weapon
{
    
    public:
        const std::string &getType();
        void setType(std::string type);
    private:
        std::string type;
};
