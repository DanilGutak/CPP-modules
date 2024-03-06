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

class PmergeMe {
public:
	static void mergeinsertSort(std::vector<int>& vec);
private:
	PmergeMe();
	PmergeMe( const PmergeMe &other );
	~PmergeMe();

	PmergeMe &operator=( const PmergeMe &other );
};

std::ostream	&operator<<( std::ostream &stream, const PmergeMe &instance );


#endif // PMERGE_ME_HPP
