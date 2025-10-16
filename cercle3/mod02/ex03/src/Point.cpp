/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:24:03 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/16 18:14:57 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//* Constructors
Point::Point() : _x(), _y()
{
#ifdef PRINT_CALLER
	std::cout << "Point default constructor called" << std::endl;
#endif
}

Point::Point(float const x, float const y) : _x(x), _y(y)
{
#ifdef PRINT_CALLER
	std::cout << "Point parameters constructor called" << std::endl;
#endif
}

Point::Point(Fixed const &x, Fixed const &y): _x(x), _y(y)
{
#ifdef PRINT_CALLER
	std::cout << "Point private parameters constructor called" << std::endl;
#endif
}

Point::Point(const Point &other) : _x(other.getX()), _y(other.getY())
{
#ifdef PRINT_CALLER
	std::cout << "Point copy constructor called" << std::endl;
#endif
}

// operators
Point &Point::operator=(const Point &other)
{
  (void)other;
#ifdef PRINT_CALLER
	std::cerr << "Point assignment operator can't perform because attributes "
				 "are constant"
			  << std::endl;
#endif
	return (*this);
}
Point Point::operator+(const Point &other) const
{
	return Point(this->_x + other._x, this->_y + other._y);
}
Point Point::operator-(const Point &other) const
{
	return Point(this->_x - other._x, this->_y - other._y);
}
Fixed Point::operator*(const Point &other) const
{
	return (this->_x * other._x - this->_y * other._y);
}
Point Point::operator/(const Point &/*unusued*/) const
{
	std::cerr << "Error: division of Point objects is not defined."
			  << std::endl;
	return *(this);
}

bool Point::operator==(const Point &other) const
{
	return (this->_x == other.getX() && this->_y == other.getY());
}

std::ostream &operator<<(std::ostream &os, const Point &p)
{
	os << "(" << p.getX() << ", " << p.getY() << ")";
	return (os);
}
//* Methods

Fixed const &Point::getX(void) const
{
	return (this->_x);
}
Fixed const &Point::getY(void) const
{
	return (this->_y);
}

//* Destructor

Point::~Point()
{
#ifdef PRINT_CALLER
	std::cout << "Point destructor called" << std::endl;
#endif
}
