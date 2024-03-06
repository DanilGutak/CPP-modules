
#include "PmergeMe.hpp"
#include <cstdlib>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./PmergeMe [positive int array]" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        if (atoi(argv[i]) <= 0 || atoi(argv[i]) > 2147483647)
        {
            std::cerr << "Error: " << argv[i] << " is not a positive integer" << std::endl;
            return 1;
        }
        // check if it has only digits or plus sign
        for (int j = 0; argv[i][j]; j++)
        {
            if (!isdigit(argv[i][j]) && argv[i][j] != '+')
            {
                std::cerr << "Error: " << argv[i] << " is not a positive integer" << std::endl;
                return 1;
            }
        }
    }
    //print array
    std::cout << "Before sort:" << std::endl;

    std::vector <int> vec;
    std::deque <int> deq;
    for (int i = 1; i < argc; i++)
    {
        vec.push_back(std::atoi(argv[i]));
        deq.push_back(std::atoi(argv[i]));
        std::cout << vec[i - 1] << " ";
    }
    std::cout << std::endl;

    //sort array for vector
    PmergeMe::mergeinsertSort(vec);
    //sort array for deque

    std::cout << "After sort:" << std::endl;
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    // time for vector

    // time for deque
    return 0;
}