#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>
#include <stdint.h>

#define PRINT_CALLER

class Ice : public AMateria
{

private:
	// _attributes

public:
	Ice();
	Ice(const Ice &other);
	~Ice();

	Ice &operator=(const Ice &other);

	Ice *clone() const;
	void use(ICharacter &target);
};

#endif
