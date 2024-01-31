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
class MutantStack: std::stack<T, std::vector<T>>{
public:
	MutantStack();
	MutantStack( const MutantStack &other );
	~MutantStack();

	MutantStack &operator=( const MutantStack &other );
};

#endif // MUTANT_STACK_HPP
