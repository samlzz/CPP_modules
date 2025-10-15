/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 19:14:37 by sliziard          #+#    #+#             */
/*   Updated: 2025/06/21 19:19:03 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <stdint.h>

#define PRINT_CALLER

class Fixed
{
public:
	Fixed();
	Fixed(int32_t const n);
	Fixed(float const f);
	Fixed(const Fixed &other);

	Fixed &operator=(const Fixed &other);

	~Fixed();

	int32_t getRawBits(void) const;
	void	setRawBits(int32_t const raw);

	int32_t toInt(void) const;
	float	toFloat(void) const;

private:
	static const int32_t _fract_bits;

	int32_t				 _fixed_point;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif
