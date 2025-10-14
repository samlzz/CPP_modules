#include "Character.hpp"
#include "AMateria.hpp"

// * Constructors

Character::Character() : _name("unnamed"), _inventory()
{
#ifdef PRINT_CALLER
	std::cout << "Character default constructor called" << std::endl;
#endif
}

Character::Character(std::string const &name) : _name(name), _inventory()
{
#ifdef PRINT_CALLER
	std::cout << "Character parameter constructor called" << std::endl;
#endif
}

Character::Character(const Character &other)
{
#ifdef PRINT_CALLER
	std::cout << "Character copy constructor called" << std::endl;
#endif
	*this = other;
}

// * Destructor

Character::~Character()
{
#ifdef PRINT_CALLER
	std::cout << "Character destructor called" << std::endl;
#endif
}

// * Operators

Character &Character::operator=(const Character &other)
{
#ifdef PRINT_CALLER
	std::cout << "Character assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		this->_name		 = other._name;
		this->_inventory = other._inventory;
	}
	return *this;
}

// * Methods

std::string const &Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria *m)
{
	if (!m)
		return;
	int i = this->_inventory.push(m);

#ifdef PRINT_CALLER
	if (i != -1)
		std::cout << this->_name << " equipped materia " << m->getType()
				  << " in slot " << i << std::endl;
	else
		std::cout << this->_name << " could not equip" << m->getType();
#endif
}

void Character::unequip(int idx)
{
	if (!this->_inventory.rm(idx))
		return;

#ifdef PRINT_CALLER
	std::cout << this->_name << " unequipped materia in slot " << idx
			  << std::endl;
#endif
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || !this->_inventory.get(idx))
		return;
	this->_inventory.get(idx)->use(target);
}
