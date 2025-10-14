#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <stdint.h>

#define PRINT_CALLER

class Point
{

public:
	Point();
	Point(float const x, float const y);
	Point(const Point &other);

	Point &operator=(const Point &other);

	Point operator+(const Point &other) const;
	Point operator-(const Point &other) const;
	Fixed operator*(const Point &other) const; // inner product
	Point operator/(const Point &other) const; // unmanaged

	bool operator==(const Point &other) const;

	~Point();

	Fixed const &getX(void) const;
	Fixed const &getY(void) const;

private:
	Fixed const _x;
	Fixed const _y;
};

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif
