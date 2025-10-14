/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:15:14 by sliziard          #+#    #+#             */
/*   Updated: 2025/06/22 16:01:43 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// *Constructors
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

// *Operators
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
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(this->_fixed_point + other.getRawBits());
	return (res);
}
Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(this->_fixed_point - other.getRawBits());
	return (res);
}
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(
		(this->_fixed_point * other.getRawBits()) >> this->_fract_bits);
	return (res);
}
Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res;

	res.setRawBits(
		(this->_fixed_point << this->_fract_bits) / other.getRawBits());
	return (res);
}

Fixed &Fixed::operator++(void)
{
	this->_fixed_point++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fixed_point++;
	return (tmp);
}
Fixed &Fixed::operator--(void)
{
	this->_fixed_point--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fixed_point--;
	return (tmp);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_fixed_point > other.getRawBits());
}
bool Fixed::operator<(const Fixed &other) const
{
	return (this->_fixed_point < other.getRawBits());
}
bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_fixed_point >= other.getRawBits());
}
bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_fixed_point <= other.getRawBits());
}
bool Fixed::operator==(const Fixed &other) const
{
	return (this->_fixed_point == other.getRawBits());
}
bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_fixed_point != other.getRawBits());
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}
Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return ((a < b) ? a : b);
}
Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}
Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return ((a > b) ? a : b);
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	return (os << fixed.toFloat());
}

// *Methods

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

// *Destructor
Fixed::~Fixed()
{
#ifdef PRINT_CALLER
	std::cout << "Fixed destructor called" << std::endl;
#endif
}
