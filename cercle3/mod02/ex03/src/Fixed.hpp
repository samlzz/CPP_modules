/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:14:37 by sliziard          #+#    #+#             */
/*   Updated: 2025/06/23 05:00:59 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>
#include <stdint.h>

class Fixed
{
public:
	Fixed();
	Fixed(int32_t const n);
	Fixed(float const f);
	Fixed(const Fixed &other);

	Fixed &operator=(const Fixed &other);

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++(void);
	Fixed  operator++(int);
	Fixed &operator--(void);
	Fixed  operator--(int);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	static Fixed	   &min(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed	   &max(Fixed &a, Fixed &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);

	~Fixed();

	int32_t getRawBits(void) const;
	void	setRawBits(int32_t const raw);

	int32_t toInt(void) const;
	float	toFloat(void) const;

private:
	int32_t				 _fixed_point;
	static const int32_t _fract_bits = 8;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
