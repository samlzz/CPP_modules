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
