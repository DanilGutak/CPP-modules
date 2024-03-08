/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:29:13 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/02/29 18:29:13 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	// Function to perform binary insertion into a sorted vector
	template <typename T>
	void binary_insert(T& vec, const int& value) {
		int pos = binary_search_insertion_point(vec, value);
		vec.insert(vec.begin() + pos, value);
	}
// Recursive merge-insertion sort function for pairs
template <typename T>
int binary_search_insertion_point_pairs(const T& vec, const std::pair<int, int>& value) {
    int low = 0;
    int high = vec.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (vec[mid].first < value.first)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

// Function to perform binary insertion into a sorted vector of pairs
template <typename T>
void binary_insert_pairs(T& vec, const std::pair<int, int>& value) {
    int pos = binary_search_insertion_point_pairs(vec, value);
    vec.insert(vec.begin() + pos, value);
}

// Recursive merge-insertion sort function for pairs
void merge_insertion_sort_pairs(std::vector<std::pair<int, int> >& pairs) {
    if (pairs.size() <= 1)
        return;

    std::vector<std::pair<int, int> > left_half(pairs.begin(), pairs.begin() + pairs.size() / 2);
    std::vector<std::pair<int, int> > right_half(pairs.begin() + pairs.size() / 2, pairs.end());

    merge_insertion_sort_pairs(left_half);
    merge_insertion_sort_pairs(right_half);

    pairs.clear();

    unsigned int i = 0, j = 0;
    while (i < left_half.size() && j < right_half.size()) {
        if (left_half[i] < right_half[j]) {
            binary_insert_pairs(pairs, left_half[i]);
            ++i;
        } else {
            binary_insert_pairs(pairs, right_half[j]);
            ++j;
        }
    }

    while (i < left_half.size()) {
        binary_insert_pairs(pairs, left_half[i]);
        ++i;
    }

    while (j < right_half.size()) {
        binary_insert_pairs(pairs, right_half[j]);
        ++j;
    }

    // Order pending elements
    std::vector<std::pair<int, int> > ordered_pairs;
    for (unsigned int k = 0; k < pairs.size(); ++k) {
        int order = pending_element_order(k);
        ordered_pairs.push_back(pairs[order]);
    }

    pairs = ordered_pairs;
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
    
    merge_insertion_sort_pairs(pairs);

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
