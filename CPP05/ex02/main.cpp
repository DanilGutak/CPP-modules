
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    
    {
        AForm *a = new PresidentialPardonForm("dummy target");
        std::cout << *a;
        Bureaucrat b("Danil", 1);
        std::cout << b;
        b.signForm(*a);
        std::cout << *a;
        std::cout << "---------------------\n";

        a->execute(b);
        std::cout << "---------------------\n";
        
        b.executeForm(*a);

        Bureaucrat c("Danil", 150);
        std::cout << c;

        c.executeForm(*a);

        delete a;

    }
    {
        AForm *a = new RobotomyRequestForm("dummy target");
        std::cout << *a;
        Bureaucrat b("Danil", 1);
        std::cout << b;
        b.signForm(*a);
        std::cout << *a;
        std::cout << "---------------------\n";

        a->execute(b);
        std::cout << "---------------------\n";
        
        b.executeForm(*a);
        b.executeForm(*a);
        b.executeForm(*a);
        b.executeForm(*a);

        Bureaucrat c("Danil", 150);
        std::cout << c;

        c.executeForm(*a);

        delete a;
    }
    {
        AForm *a = new ShrubberyCreationForm(" target mega");
        std::cout << *a;
        Bureaucrat b("Danil", 1);
        std::cout << b;
        b.signForm(*a);
        std::cout << *a;
        a->execute(b);
        
        b.executeForm(*a);
        b.executeForm(*a);

        Bureaucrat c("Danil", 150);
        std::cout << c;

        c.executeForm(*a);

        delete a;
    }
    return (0);
}