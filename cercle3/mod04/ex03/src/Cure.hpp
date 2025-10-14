#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <stdint.h>

#define PRINT_CALLER

class Cure : public AMateria
{

private:
	// _attributes

public:
	Cure();
	Cure(const Cure &other);
	~Cure();

	Cure &operator=(const Cure &other);

	Cure *clone() const;
	void  use(ICharacter &target);
};

#endif
