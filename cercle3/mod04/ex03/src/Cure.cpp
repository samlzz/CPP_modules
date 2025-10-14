#include "Cure.hpp"

// *Constructors
Cure::Cure() : AMateria("cure")
{
#ifdef PRINT_CALLER
	std::cout << "Cure default constructor called" << std::endl;
#endif
}

Cure::Cure(const Cure &other) : AMateria(other)
{
#ifdef PRINT_CALLER
	std::cout << "Cure copy constructor called" << std::endl;
#endif
}
// *Destructor
Cure::~Cure()
{
#ifdef PRINT_CALLER
	std::cout << "Cure destructor called" << std::endl;
#endif
}

// *Operators

Cure &Cure::operator=(const Cure &other)
{
#ifdef PRINT_CALLER
	std::cout << "Cure assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return *this;
}

//* Methods

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
			  << std::endl;
}