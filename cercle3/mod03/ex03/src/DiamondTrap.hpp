#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <stdint.h>

#define PRINT_CALLER

class DiamondTrap : public FragTrap, public ScavTrap
{

public:
	DiamondTrap(const std::string &name);
	DiamondTrap(const DiamondTrap &other);
	DiamondTrap &operator=(const DiamondTrap &other);
	~DiamondTrap();

	void whoAmI(void);
	using ScavTrap::attack;

private:
	std::string _name;
};

#endif
