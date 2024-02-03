
#include "easyfind.hpp"

int main()
{
    std::cout  << "------------------" << std::endl;
    std::cout  << "Test with vector:" << std::endl;
    std::vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i);
    try
    {
        std::cout << *easyfind(v, 2) << std::endl;
        std::cout << *easyfind(v, 4) << std::endl;
        std::cout << *easyfind(v, 1000) << std::endl;
        std::cout << *easyfind(v, -1) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;

    std::cout  << "------------------" << std::endl;
    std::cout  << "Test with vector:" << std::endl;
    const std::vector<int> cv(v);
    try
    {
        std::cout << *easyfind(cv, 2) << std::endl;
        std::cout << *easyfind(cv, 4) << std::endl;
        std::cout << *easyfind(cv, 1000) << std::endl;
        std::cout << *easyfind(cv, -1) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "Not found" << std::endl;
    }
    return 0;
    

}