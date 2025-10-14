#include "WrongCat.hpp"

//* Constructors
WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
#ifdef PRINT_CALLER
	std::cout << "WrongCat default constructor called" << std::endl;
#endif
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
#ifdef PRINT_CALLER
	std::cout << "WrongCat copy constructor called" << std::endl;
#endif
}

// operators
WrongCat &WrongCat::operator=(const WrongCat &other)
{
#ifdef PRINT_CALLER
	std::cout << "WrongCat assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	return *this;
}

//* Destructor

WrongCat::~WrongCat()
{
#ifdef PRINT_CALLER
	std::cout << "WrongCat destructor called" << std::endl;
#endif
}

void WrongCat::makeSound() const
{
	std::cout << "Gouzi gouza" << std::endl;
}