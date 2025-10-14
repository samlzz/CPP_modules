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

Point::Point(const Point &other)
{
#ifdef PRINT_CALLER
	std::cout << "Point copy constructor called" << std::endl;
#endif
	*this = other;
}

// operators
Point &Point::operator=(const Point &other)
{
#ifdef PRINT_CALLER
	std::cerr << "Point assignment operator can't perform because attributes "
				 "are constant"
			  << std::endl;
#endif
	if (this != &other)
	{
	}
	return (*this);
}
Point Point::operator+(const Point &other) const
{
	return Point(
		(this->_x + other._x).toFloat(), (this->_y + other._y).toFloat());
}
Point Point::operator-(const Point &other) const
{
	return Point(
		(this->_x - other._x).toFloat(), (this->_y - other._y).toFloat());
}
Fixed Point::operator*(const Point &other) const
{
	return (this->_x * other._x + this->_y * other._y);
}
Point Point::operator/(const Point &other) const
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
