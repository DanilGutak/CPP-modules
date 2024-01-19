
#pragma once

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP


# include <string>

class ClapTrap {
protected:
	std::string	Name;
	int	hp;
	int	mp;
	int	dmg;

public:
	ClapTrap();
	ClapTrap( std::string Name);
	ClapTrap( const ClapTrap &other );
	virtual ~ClapTrap();
	virtual void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap &operator=( const ClapTrap &other );
};



#endif // CLAP_TRAP_HPP
