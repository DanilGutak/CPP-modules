
#pragma once

#include "ClapTrap.hpp"


# include <string>


class FragTrap: public ClapTrap {
public:
	FragTrap();
	FragTrap( std::string Name);
	FragTrap( const FragTrap &other );
	~FragTrap();
	void highFivesGuys(void);


	FragTrap &operator=( const FragTrap &other );
};