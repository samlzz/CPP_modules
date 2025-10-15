/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:15:14 by sliziard          #+#    #+#             */
/*   Updated: 2025/06/21 19:19:23 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int32_t Fixed::_fract_bits = 8;

//* Constructors
Fixed::Fixed() : _fixed_point(0)
{
#ifdef PRINT_CALLER
	std::cout << "Fixed default constructor called" << std::endl;
#endif
}

Fixed::Fixed(int32_t const n) : _fixed_point(n << this->_fract_bits)
{
#ifdef PRINT_CALLER
	std::cout << "Fixed parameters constructor called" << std::endl;
#endif
}

Fixed::Fixed(float const f) : _fixed_point(roundf(f * (1 << this->_fract_bits)))
{
#ifdef PRINT_CALLER
	std::cout << "Fixed parameters constructor called" << std::endl;
#endif
}

Fixed::Fixed(const Fixed &other)
{
#ifdef PRINT_CALLER
	std::cout << "Fixed copy constructor called" << std::endl;
#endif
	*this = other;
}

// operators
Fixed &Fixed::operator=(const Fixed &other)
{
#ifdef PRINT_CALLER
	std::cout << "Fixed assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		this->_fixed_point = other.getRawBits();
	}
	return *this;
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	return (os << fixed.toFloat());
}

//* Methods

int32_t Fixed::toInt(void) const
{
	return (this->_fixed_point / (1 << this->_fract_bits));
}
float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_fixed_point) / (1 << this->_fract_bits));
}

int32_t Fixed::getRawBits(void) const
{
	return (this->_fixed_point);
}
void Fixed::setRawBits(int32_t const raw)
{
	this->_fixed_point = raw;
}

//* Destructor
Fixed::~Fixed()
{
#ifdef PRINT_CALLER
	std::cout << "Fixed destructor called" << std::endl;
#endif
}
