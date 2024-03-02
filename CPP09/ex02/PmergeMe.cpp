/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:29:13 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/02/29 18:29:13 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe( const PmergeMe & ) {}
PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=( const PmergeMe & ) {
	return (*this);
}


void PmergeMe::mergeinsertSort(std::vector<int>& vec) {
    //base case
	if (vec.size() < 2)
		return;
	// create iterators for the beginning and end of the vector and the middle of the vector

	std::vector<int>::iterator begin(vec.begin()), end(vec.end());
	std::vector<int>::iterator middle = vec.begin() + (vec.size() / 2);

	// create two vectors to hold the first and second half of the original vector except for the last element if the original vector has an odd number of elements
	std::vector<int> left(begin, middle);
	int stragler = vec.size() % 2 == 0 ? 0 : *(--end);

	std::vector<int> right(middle, end);

	// sort pairs in the left and right vectors
	for (unsigned int i = 0; i < left.size() - 1; i++)
		if (left[i] > right[i])
			std::swap(left[i], right[i]);
	
	// create copies of the left and right vectors
	std::vector <int> right_copy = right;
	std::vector <int> left_copy = left;
	// recursively call mergeinsertSort on the right vector
	PmergeMe::mergeinsertSort(right);

	// connect elements of the left and right vectors to the original vector

	for (unsigned int i = 0; i < right.size(); i++)
	{
		//find ith element in right vector in the copy right vector
		std::vector<int>::iterator it = std::find(right_copy.begin(), right_copy.end(), right[i]);
		
	}




	

}