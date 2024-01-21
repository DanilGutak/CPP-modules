
#include "Bureaucrat.hpp"

int main()
{
    try 
    {
        Bureaucrat a("Danil", 1);
        std::cout << a;
        a.decrementGrade();
        std::cout << a;
        a.incrementGrade();
        std::cout << a;
        a.decrementGrade();
        std::cout << a;
        a.incrementGrade();
        std::cout << a;
        a.incrementGrade();
        std::cout << a;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        Bureaucrat a("Vlad", 151);}
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;}
    std::cout << std::endl;
    
    try {
        Bureaucrat a("Kevin", -1);}
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;}    

    
    return (0);
}