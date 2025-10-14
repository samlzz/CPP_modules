#include "Ice.hpp"

// *Constructors
Ice::Ice() : AMateria("ice")
{
#ifdef PRINT_CALLER
	std::cout << "Ice default constructor called" << std::endl;
#endif
}

Ice::Ice(const Ice &other) : AMateria(other)
{
#ifdef PRINT_CALLER
	std::cout << "Ice copy constructor called" << std::endl;
#endif
}
// *Destructor
Ice::~Ice()
{
#ifdef PRINT_CALLER
	std::cout << "Ice destructor called" << std::endl;
#endif
}

// *Operators

Ice &Ice::operator=(const Ice &other)
{
#ifdef PRINT_CALLER
	std::cout << "Ice assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

//* Methods

Ice *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
