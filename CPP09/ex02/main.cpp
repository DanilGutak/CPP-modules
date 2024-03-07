
#include "PmergeMe.hpp"

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>

// Function to calculate the nth Jacobsthal number (0-indexed)
int jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Function to determine the order of pending elements
std::vector<int> pending_element_order(int n) {
    std::vector<int> order;
    for (int i = 0; jacobsthal(i) < n; ++i)
        order.push_back(jacobsthal(i));
    order.push_back(n); // Add n to the order
    return order;
}

// Binary search to find the insertion point
template <typename T>
int binary_search_insertion_point(const std::vector<T>& vec, const T& value) {
    int low = 0;
    int high = vec.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (vec[mid] < value)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Function to perform binary insertion into a sorted vector
template <typename T>
void binary_insert(std::vector<T>& vec, const T& value) {
    int pos = binary_search_insertion_point(vec, value);
    vec.insert(vec.begin() + pos, value);
}

// Merge-insertion sort function
void merge_insertion_sort(std::vector<int>& A) {
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < A.size(); i += 2) {
        if (A[i] > A[i + 1])
            std::swap(A[i], A[i + 1]);
        pairs.push_back(std::make_pair(A[i], A[i + 1]));
    }
    
    std::sort(pairs.begin(), pairs.end());

    std::vector<int> main_chain;
    std::vector<int> pending_elements;
    for (size_t i = 0; i < pairs.size(); ++i) {
        main_chain.push_back(pairs[i].first);
        pending_elements.push_back(pairs[i].second);
    }

    if (A.size() % 2 != 0)
        pending_elements.push_back(A[A.size() - 1]);

    std::vector<int> main_chain_positions(main_chain.size());
    for (size_t i = 0; i < main_chain_positions.size(); ++i)
        main_chain_positions[i] = i;

    for (size_t i = 0; i < pending_elements.size(); ++i) {
        int index = pending_element_order(i).back();
        int insert_index = binary_search_insertion_point(main_chain, pending_elements[index]);
        main_chain_positions.insert(main_chain_positions.begin() + insert_index, i);
        main_chain.insert(main_chain.begin() + insert_index, pending_elements[i]);
    }

    A = main_chain;
}
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
    merge_insertion_sort(vec);
    clock_t end = clock();
    
    double vector_time_data = (double)(end - start) / CLOCKS_PER_SEC;
    double vector_time_algo = (double)(end - start2) / CLOCKS_PER_SEC;

    std::cout << "Time for vector data management: " << vector_time_data << " seconds" << std::endl;
    std::cout << "Time for vector algorithm: " << vector_time_algo << " seconds" << std::endl;
    //sort array for deque

    std::cout << "After sort:" << std::endl;
    for (unsigned int i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    // time for vector

    // time for deque
    return 0;
}