/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:23:57 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/16 18:58:21 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <stdint.h>

class Point
{

public:
	Point();
	Point(float const x, float const y);
	Point(Fixed const &x, Fixed const &y);
	Point(const Point &other);

	Point &operator=(const Point &other);

	Point operator+(const Point &other) const;
	Point operator-(const Point &other) const;
	Fixed operator*(const Point &other) const; // inner product
	Point operator/(const Point &/*unusued*/) const; // unmanaged

	bool operator==(const Point &other) const;

	~Point();

	Fixed const &getX(void) const;
	Fixed const &getY(void) const;

	Fixed	crossProduct(const Point &other) const;

private:
	Fixed const _x;
	Fixed const _y;
};

std::ostream &operator<<(std::ostream &os, const Point &p);

#endif
