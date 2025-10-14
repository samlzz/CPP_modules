#include "AMateria.hpp"

// *Constructors
AMateria::AMateria()
{
#ifdef PRINT_CALLER
	std::cout << "AMateria default constructor called" << std::endl;
#endif
}

AMateria::AMateria(std::string const &type) : _type(type)
{
#ifdef PRINT_CALLER
	std::cout << "AMateria parameters constructor called" << std::endl;
#endif
}

AMateria::AMateria(const AMateria &other)
{
#ifdef PRINT_CALLER
	std::cout << "AMateria copy constructor called" << std::endl;
#endif
	*this = other;
}
// *Destructor
AMateria::~AMateria()
{
#ifdef PRINT_CALLER
	std::cout << "AMateria destructor called" << std::endl;
#endif
}

// *Operators

AMateria &AMateria::operator=(const AMateria &other)
{
#ifdef PRINT_CALLER
	std::cout << "AMateria assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		this->_type = std::string(other.getType());
	}
	return *this;
}

//* Methods

std::string const &AMateria::getType() const
{
	return (this->_type);
}