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

const int PmergeMe::Jacobsthal[] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461,
 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 
 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531};
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
	for (unsigned int i = 0; i < vec.size() / 2; i++)
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
		
		if (it == right_copy.end())
			continue;
		// retrieve the index of the element in the copy right vector
		int index = std::distance(right_copy.begin(), it);

		// replace the element from the copy left vector at the index of the element in the left vector
		std::swap(left[i], left_copy[index]);
	}

	std::vector <int> ret;
	// add strangler to the left vector if it exists
	if (stragler)
	{
		left.push_back(stragler);
	}

	ret = right;
	// add the elements of the left vector to the right vector since the left vector is sorted and the first elem is the smallest one
	ret.insert(ret.begin(), left[0]);

	



	vec = ret;
	

}