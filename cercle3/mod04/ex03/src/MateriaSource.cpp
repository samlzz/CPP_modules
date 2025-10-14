#include "MateriaSource.hpp"

// *Constructors
MateriaSource::MateriaSource() : _memory()
{
#ifdef PRINT_CALLER
	std::cout << "MateriaSource default constructor called" << std::endl;
#endif
}

MateriaSource::MateriaSource(const MateriaSource &other)
	: _memory(other._memory)
{
#ifdef PRINT_CALLER
	std::cout << "MateriaSource copy constructor called" << std::endl;
#endif
}
// *Destructor
MateriaSource::~MateriaSource()
{
#ifdef PRINT_CALLER
	std::cout << "MateriaSource destructor called" << std::endl;
#endif
}

// *Operators

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
#ifdef PRINT_CALLER
	std::cout << "MateriaSource assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		this->_memory = other._memory;
	}
	return *this;
}

//* Methods

void MateriaSource::learnMateria(AMateria *m)
{
	this->_memory.push(m);
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	AMateria *found;

	for (size_t i = 0; i < 4; i++)
	{
		found = this->_memory.get(i);
		if (found && found->getType() == type)
			return found->clone();
	}
	return 0;
}