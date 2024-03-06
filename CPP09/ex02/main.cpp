
#include "PmergeMe.hpp"


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
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Before sort:" << std::endl;

    std::vector <int> vec;
    std::deque <int> deq;
    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
    clock_t start = clock();
    for (int i = 1; i < argc; i++)
    {
        vec.push_back(std::atoi(argv[i]));
    }
    clock_t start2 = clock();
    PmergeMe::mergeinsertSort(vec);
    clock_t end = clock();
    
    double vector_time_data = (double)(end - start) / CLOCKS_PER_SEC;
    double vector_time_algo = (double)(end - start2) / CLOCKS_PER_SEC;

    std::cout << "Time for vector data management: " << vector_time_data << " seconds" << std::endl;
    std::cout << "Time for vector algorithm: " << vector_time_algo << " seconds" << std::endl;
    //sort array for deque

    std::cout << "After sort:" << std::endl;
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    // time for vector

    // time for deque
    return 0;
}