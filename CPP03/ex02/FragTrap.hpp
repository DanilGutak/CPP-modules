/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danil.gutak <danil.gutak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 18:15:14 by danil.gutak          #+#    #+#             */
/*   Updated: 2024/01/18 18:15:14 by danil.gutak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"


# include <string>


class FragTrap: public ClapTrap {
public:
	FragTrap();
	FragTrap( std::string Name);
	FragTrap( const FragTrap &other );
	~FragTrap();
	void attack(const std::string& target);
	void highFivesGuys(void);


	FragTrap &operator=( const FragTrap &other );
};