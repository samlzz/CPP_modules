/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:25:03 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/15 15:25:03 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int32_t Fixed::_fract_bits = 8;

//* Constructors
Fixed::Fixed() : _fixed_point(0)
{
#ifdef PRINT_CALLER
	std::cout << "Fixed default constructor called" << std::endl;
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

//* Methods

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
