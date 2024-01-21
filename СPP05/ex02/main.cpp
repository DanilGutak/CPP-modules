
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    
    {
        AForm *a = new PresidentialPardonForm("Danil");
        
        delete a;

    }
    
    return (0);
}