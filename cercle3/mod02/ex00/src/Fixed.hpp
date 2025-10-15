/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:24:59 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/15 15:25:00 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <stdint.h>

#define PRINT_CALLER

class Fixed
{

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int32_t getRawBits(void) const;
	void	setRawBits(int32_t const raw);

private:
	static const int32_t _fract_bits;

	int32_t				 _fixed_point;
};

#endif
