#include "Harl.hpp"
int main()
{
    Harl harl;
    harl.complain("INFO");
    std::cout << "------------------------\n";
    harl.complain("DEBUG");
    std::cout << "------------------------\n";
    harl.complain("WARNING");
    std::cout << "------------------------\n";
    harl.complain("ERROR");
    std::cout << "------------------------\n";
    harl.complain("I");
    std::cout << "------------------------\n";
    harl.complain("love");
    std::cout << "------------------------\n";
    harl.complain("lol");
    std::cout << "------------------------\n";
    harl.complain("INFO");
    std::cout << "------------------------\n";
    harl.complain("INFO");
    std::cout << "------------------------\n";
    
    
}