#include "PmergeMe.hpp"

int isSorted(std::vector <int> vec) {
    for (unsigned int i = 1; i < vec.size(); ++i) {
        if (vec[i - 1] > vec[i]) {
            return false; 
        }
    }
    return true; // Array is sorted in ascending order
}
// Function to calculate the nth Jacobsthal number
int jacobsthal(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}
// Function to determine the order of pending elements
int pending_element_order(int n) {
    std::vector<int> order;
    for (int i = 0; jacobsthal(i) < n; ++i){
        order.push_back(jacobsthal(i));}
	order.push_back(n);
    return order.size() - 1;
}


