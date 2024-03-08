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
std::vector<int> pending_element_order(int n);

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

// Merge-insertion sort function
template <typename T>
void merge_insertion_sort(T &A) {
    std::vector<std::pair<int, int> > pairs;
    for (unsigned int i = 0; i + 1 < A.size(); i += 2) {
        if (A[i] > A[i + 1])
            std::swap(A[i], A[i + 1]);
        pairs.push_back(std::make_pair(A[i], A[i + 1]));
    }
    
    std::sort(pairs.begin(), pairs.end());

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
        int index = pending_element_order(i).back();
        int insert_index = binary_search_insertion_point(main_chain, pending_elements[index]);
        main_chain_positions.insert(main_chain_positions.begin() + insert_index, i);
        main_chain.insert(main_chain.begin() + insert_index, pending_elements[i]);
    }

    A = main_chain;
}

#endif // PMERGE_ME_HPP
