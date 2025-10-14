#include "Fixed.hpp"

//* Constructors
Fixed::Fixed() : _fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int32_t const fixed_point) : _fixed_point(fixed_point)
{
	std::cout << "Parameters constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// operators
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixed_point = other.getRawBits();
	}
	return (*this);
}

//* Methods

int32_t Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixed_point);
}
void Fixed::setRawBits(int32_t const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixed_point = raw;
}

//* Destructor

Fixed::~Fixed()
{
	std::cout << "Fixed destructor called" << std::endl;
}
