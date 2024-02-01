
#include "RPN.hpp"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./rpn \"expression\"\n";
        return 1;
    }
    std::string str = argv[1];
    std::cout << "Expression: " << str << "\n";
    std::cout << "Result: " << RPN::validate_input(str) << "\n";
    std::cout << "Result: " << RPN::calculate(str) << "\n";
}