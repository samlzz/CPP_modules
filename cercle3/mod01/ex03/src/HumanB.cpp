#include "HumanB.hpp"

//* Constructors
HumanB::HumanB()
{
	std::cout << "HumanB default constructor called" << std::endl;
}

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
	std::cout << "HumanB constructor called" << std::endl;
}

HumanB::HumanB(const HumanB &other) : _name(other._name), _weapon(other._weapon)
{
	std::cout << "HumanB copy constructor called" << std::endl;
}

// operators
HumanB &HumanB::operator=(const HumanB &other)
{
	std::cout << "HumanB assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name	  = other._name;
		this->_weapon = other._weapon;
	}
	return *this;
}

//* Methods

void HumanB::attack() const
{
	if (!this->_weapon)
		return;
	std::cout << this->_name << " attack with their "
			  << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

//* Destructor

HumanB::~HumanB()
{
	std::cout << "HumanB destructor called" << std::endl;
}
