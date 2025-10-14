#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <stdint.h>

class Fixed
{

public:
	Fixed();
	Fixed(int32_t const fixed_point);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	int32_t getRawBits(void) const;
	void	setRawBits(int32_t const raw);

private:
	int32_t				 _fixed_point;
	static const int32_t _fract_bits = 8;
};

#endif
