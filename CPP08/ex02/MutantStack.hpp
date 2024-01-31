/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:14:25 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/31 15:14:25 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP


# include <string>

template <typename T>
class MutantStack: std::stack<T>{
public:
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin() {
		return (std::stack<T>::c.begin());
	}
	iterator end() {
		return (std::stack<T>::c.end());
	}
	const_iterator begin() const {
		return (std::stack<T>::c.begin());
	}
	const_iterator end() const {
		return (std::stack<T>::c.end());
	}
	reverse_iterator rbegin() {
		return (std::stack<T>::c.rbegin());
	}
	reverse_iterator rend() {
		return (std::stack<T>::c.rend());
	}
	const_reverse_iterator rbegin() const {
		return (std::stack<T>::c.rbegin());
	}
	const_reverse_iterator rend() const {
		return (std::stack<T>::c.rend());
	}
};

#endif // MUTANT_STACK_HPP
