#pragma once

#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP


# include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstdlib>
#include <iomanip>

int jacobsthal(int n);
int pending_element_order(int n);

int pending_element_position(unsigned int  n, int size) {
    std::vector<int> positions;
    for (int i = 0; jacobsthal(i) < size; ++i) {
        positions.push_back(jacobsthal(i));
    }
    if (n < positions.size()) {
        return positions[n];
    }
    return size - 1; // If beyond the last Jacobsthal number, use the last element
}

// Binary search to find the insertion point
template <typename T>
int binary_search_insertion_point(const T& vec, const int& value) {
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
template <typename T>
void merge(std::vector<T>& vec, int start, int mid, int end) {
    std::vector<T> temp;
    int i = start, j = mid;
    while (i < mid && j < end) {
        if (vec[i] < vec[j]) {
            temp.push_back(vec[i++]);
        } else {
            temp.push_back(vec[j++]);
        }
    }
    while (i < mid) {
        temp.push_back(vec[i++]);
    }
    while (j < end) {
        temp.push_back(vec[j++]);
    }
    std::copy(temp.begin(), temp.end(), vec.begin() + start);
}

// Recursive function to sort pairs using the Ford-Johnson merge-insertion sort algorithm
template <typename T>
void merge_insertion_sort_pairs(std::vector<T>& pairs, int start, int end) {
    if (end - start <= 1) return;

    int mid = start + (end - start) / 2;
    merge_insertion_sort_pairs(pairs, start, mid);
    merge_insertion_sort_pairs(pairs, mid, end);
    merge(pairs, start, mid, end);

    // Insert pending elements using the Jacobsthal sequence
    for (int i = 0; i < mid - start; ++i) {
        int position = pending_element_position(i, end - start);
        if (position != i) {
            std::rotate(pairs.begin() + start + i, pairs.begin() + start + position, pairs.begin() + start + position + 1);
        }
    }
}

// Merge-insertion sort function
template <typename T>
void merge_insertion_sort(T &A) {
    std::vector<std::pair<int, int> > pairs;
    for (unsigned int i = 0; i + 1 < A.size(); i += 2) {
        if (A[i] > A[i + 1])
            std::swap(A[i], A[i + 1]);
        pairs.push_back(std::make_pair(A[i], A[i + 1]));
    }
    
    merge_insertion_sort_pairs(pairs, 0,pairs.size());

    T main_chain;
    T pending_elements;
    for (unsigned int i = 0; i < pairs.size(); ++i) {
        main_chain.push_back(pairs[i].first);
        pending_elements.push_back(pairs[i].second);
    }

    if (A.size() % 2 != 0)
        pending_elements.push_back(A[A.size() - 1]);

    T main_chain_positions(main_chain.size());
    for (unsigned int i = 0; i < main_chain_positions.size(); ++i)
        main_chain_positions[i] = i;

    for (unsigned int i = 0; i < pending_elements.size(); ++i) {
        int index = pending_element_order(i);
        int insert_index = binary_search_insertion_point(main_chain, pending_elements[index]);
        main_chain_positions.insert(main_chain_positions.begin() + insert_index, i);
        main_chain.insert(main_chain.begin() + insert_index, pending_elements[i]);
    }

    A = main_chain;
}

#endif // PMERGE_ME_HPP
