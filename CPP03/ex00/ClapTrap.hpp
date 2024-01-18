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

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP


# include <string>

# define DEFAULT_NAME
# define DEFAULT_HP
# define DEFAULT_MP
# define DEFAULT_DMG

class ClapTrap {
private:
	std::string	Name;
	int	hp;
	int	mp;
	int	dmg;

public:
	ClapTrap();
	ClapTrap( std::string Name);
	ClapTrap( const ClapTrap &other );
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap &operator=( const ClapTrap &other );
};



#endif // CLAP_TRAP_HPP
