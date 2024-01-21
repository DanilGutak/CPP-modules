
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form a("ApplyForm", 3, 3);
    std::cout << a;
    Bureaucrat b("Danil", 3);
    std::cout << b;
    b.signForm(a);
    std::cout << a;
    b.signForm(a);     
    std::cout << "---------------------\n";
    Form c("ApplyForm2", 3, 3);
    b.decrementGrade();
    b.signForm(c);
    std::cout << "---------------------\n";

    Form d("ApplyForm3", 1, 1);
    try
    {
        d.beSigned(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    
    return (0);
}