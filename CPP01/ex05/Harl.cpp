 #include "Harl.hpp"
void Harl::debug(void)
{
    std::cout << "[DEBUG]" << "\n";
    std::cout << "debug_level.txt" << "\n";

}
void Harl::info(void)
{
    std::cout << "[INFO]" << "\n";
    std::cout << "info_level.txt" << "\n";

}
void Harl::warning(void)
{
    std::cout << "[WARNING]" << "\n";
    std::cout << "warning_level.txt" << "\n";

}
 void Harl::error(void)
{
    std::cout << "[ERROR]" << "\n";
    std::cout << "error_level.txt" << "\n";
}


void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO","WARNING", "ERROR"};
    void (Harl::*funcs[4])() = { &Harl::debug, &Harl::info,&Harl::warning,&Harl::error};
    for (int i = 0; i< 4 ; i++)
    {
        if (level == levels[i])
        {
            (this->*funcs[i])();
            return ;
        }
    }
    std::cout << "level not found\n";
}