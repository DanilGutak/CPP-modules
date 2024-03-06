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
int binary_search(std::vector<int> const &vec, int target) {
	int low = 0;
	int high = vec.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;

		if (vec[mid] == target) {
			return mid;
		} else if (vec[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return low;
}

std::vector <int> createJacobsthal() {
	
	std::vector<int> Jacobsthal(32);
	Jacobsthal[0] = 0;
	Jacobsthal[1] = 1;
	for (int i = 2; i < 33; i++) {
		Jacobsthal[i] = Jacobsthal[i - 1] + 2 * Jacobsthal[i - 2];
	}
	return Jacobsthal;
}
void PmergeMe::mergeinsertSort(std::vector<int>& vec) {

    
	std::vector<int> Jacobsthal = createJacobsthal();
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
	// print jacobsthal numbers
	std::cout << std::endl;
	for (unsigned int i = 0; i < right.size(); i++)
	{
		//find ith element in right vector in the copy right vector
		std::vector<int>::iterator it = std::find(right_copy.begin(), right_copy.end(), right[i]);
		
		if (it == right_copy.end())
			continue;
		// retrieve the index of the element in the copy right vector
		int index = std::distance(right_copy.begin(), it);

		// replace the element from the copy left vector at the index of the element in the left vector
		left[i] = left_copy[index];
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
	std::vector <int> range;
	int index;
	for (int i = 1; i <= std::distance(Jacobsthal.begin(), std::lower_bound(Jacobsthal.begin(), Jacobsthal.end() , left.size() - 1)); i++) {
		if ((static_cast<int>(left.size()) - 1) < Jacobsthal[i]) {
			index = static_cast<int>(left.size()) - 1;
		} else
			index = Jacobsthal[i];
		while (index != Jacobsthal[i - 1]) {
			range = std::vector <int>(ret.begin(), std::find(ret.begin(), ret.end(), right[index]) + 1);
			ret.insert(std::lower_bound(ret.begin(),ret.end(),left[index]), left[index]);
			index--;
		}
	}
	vec = ret;
}