
#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>



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
            std::cerr << "Error: \"" << argv[i] << "\" is not a positive integer" << std::endl;
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

    for (int i = 1; i < argc; i++)
    {
        std::cout << argv[i] << " ";
    }
    std::cout << std::endl;
    clock_t start = clock();

    std::vector <int> vec;
    for (int i = 1; i < argc; i++)
    {
        vec.push_back(std::atoi(argv[i]));
    }
    if (isSorted(vec) == 1)
    {
        std::cout << "Array is sorted!" << std::endl;
        return 0;
    }
    clock_t start2 = clock();
    merge_insertion_sort(vec);
    clock_t end = clock();
    
    double time_data = (double)(start2 - start) / CLOCKS_PER_SEC;
    double time_algo = (double)(end - start2) / CLOCKS_PER_SEC;
    
    std::cout << "After sort:" << std::endl;
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;

    std::cout << "Time for vector data management: " << time_data << " seconds" << std::endl;
    std::cout << "Time for vector algorithm: " << time_algo << " seconds" << std::endl;

    start = clock();
    std::deque <int> deq;
    for (int i = 1; i < argc; i++)
    {
        deq.push_back(std::atoi(argv[i]));
    }
    start2 = clock();
    merge_insertion_sort(deq);
    end = clock();
    
    time_data = (double)(start2 - start) / CLOCKS_PER_SEC;
    time_algo = (double)(end - start2) / CLOCKS_PER_SEC;

    std::cout << "Time for deque data management: " << time_data << " seconds" << std::endl;
    std::cout << "Time for deque algorithm: " << time_algo << " seconds" << std::endl;
    return 0;
}