# include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string& stringREF = str;
    std::string *stringPTR = &str;
    
    std::cout << &str << "\n";
    std::cout << &stringREF << "\n";
    std::cout << &stringPTR << "\n\n";

    std::cout << str << "\n";
    std::cout << stringREF << "\n";
    std::cout << *stringPTR << "\n";

}