
#include <iostream>
#include  <iomanip>
#include "Contact.hpp"
class Phonebook
{
    public:
        void    add(int i);
        void    search(void);
    private:
        Contact contacts[8];
    
};
