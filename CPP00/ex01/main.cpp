#include "Phonebook.hpp"
#include <ostream>
int main(void)
{
    Phonebook phonebook;
    std::string input;
    int i = 0;
    while (1)
    {
        if (i == 8)
            i = 0; 
        std::cout << "Type your command:\n" ;
        std::getline(std::cin, input);
        if (std::cin.eof())
            return (1);
        if (input == "ADD")
            phonebook.add(i++);
        if (input == "SEARCH")
            phonebook.search();
        if (input == "EXIT")
            return (0);
    }

}