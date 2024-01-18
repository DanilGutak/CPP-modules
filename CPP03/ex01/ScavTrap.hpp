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


class ScavTrap: public ClapTrap {
public:
	ScavTrap();
	ScavTrap( std::string Name);
	ScavTrap( const ScavTrap &other );
	~ScavTrap();
	void attack(const std::string& target);
	void guardGate();


	ScavTrap &operator=( const ScavTrap &other );
};