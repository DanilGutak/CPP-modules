
#include "RPN.hpp"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./rpn \"expression\"\n";
        return 1;
    }
    std::string str = argv[1];
    try
    {
        std::cout << RPN::calculate(str) << "\n";
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
}