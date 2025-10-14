#include "ASlot.hpp"

// *Constructors
ASlot::ASlot()
{
#ifdef PRINT_CALLER
	std::cout << "ASlot default constructor called" << std::endl;
#endif
	for (int i = 0; i < 4; ++i)
		this->_slots[i] = NULL;
}

ASlot::ASlot(const ASlot &other)
{
#ifdef PRINT_CALLER
	std::cout << "ASlot copy constructor called" << std::endl;
#endif
	*this = other;
}
// *Destructor
ASlot::~ASlot()
{
#ifdef PRINT_CALLER
	std::cout << "ASlot destructor called" << std::endl;
#endif
	for (int i = 0; i < 4; ++i)
	{
		if (this->_slots[i])
			delete this->_slots[i];
	}
}

// *Operators

ASlot &ASlot::operator=(const ASlot &other)
{
#ifdef PRINT_CALLER
	std::cout << "ASlot assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (this->_slots[i])
				delete this->_slots[i];
			this->_slots[i] = other._slots[i] ? other._slots[i]->clone() : NULL;
		}
	}
	return *this;
}

//* Methods

int ASlot::push(AMateria *m)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_slots[i] == NULL)
		{
			this->_slots[i] = m;
			return (i);
		}
	}
	return (-1);
}

AMateria *ASlot::rm(int idx)
{
	if (idx < 0 || idx >= 4)
		return (NULL);
	AMateria *deleted = this->_slots[idx];
	this->_slots[idx] = NULL;
	return (deleted);
}

AMateria *ASlot::get(int idx)
{
	if (idx < 0 || idx > 4)
		return (NULL);
	return (this->_slots[idx]);
}