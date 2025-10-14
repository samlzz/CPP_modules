#include "DiamondTrap.hpp"

//* Constructors
DiamondTrap::DiamondTrap(const std::string &name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name),
	  _name(name)
{
#ifdef PRINT_CALLER
	std::cout << "DiamondTrap default constructor called" << std::endl;
#endif
	this->_hit	   = FragTrap::_hit;
	this->_energy  = ScavTrap::_energy;
	this->_dammage = FragTrap::_dammage;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other), _name(other._name)
{
#ifdef PRINT_CALLER
	std::cout << "DiamondTrap copy constructor called" << std::endl;
#endif
	*this = other;
}

// operators
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
#ifdef PRINT_CALLER
	std::cout << "DiamondTrap assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

//* Methods

void DiamondTrap::whoAmI()
{
	std::cout << "I am " << this->_name << ", and my ClapTrap name is "
			  << this->ClapTrap::_name << std::endl;
}

//* Destructor

DiamondTrap::~DiamondTrap()
{
#ifdef PRINT_CALLER
	std::cout << "DiamondTrap destructor called" << std::endl;
#endif
}
