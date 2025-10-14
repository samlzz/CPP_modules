#ifndef ASLOT_HPP
#define ASLOT_HPP

#include "AMateria.hpp"
#include <iostream>
#include <stdint.h>

#define PRINT_CALLER

class ASlot
{

protected:
	AMateria *_slots[4];

public:
	ASlot();
	ASlot(const ASlot &other);
	~ASlot();

	ASlot &operator=(const ASlot &other);

	int		  push(AMateria *m);
	AMateria *rm(int idx);
	AMateria *get(int idx);
};

#endif
