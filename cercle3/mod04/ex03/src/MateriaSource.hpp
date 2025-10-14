#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "ASlot.hpp"
#include "IMateriaSource.hpp"

#define PRINT_CALLER

class MateriaSource : public IMateriaSource
{

private:
	ASlot _memory;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	~MateriaSource();

	MateriaSource &operator=(const MateriaSource &other);

	void	  learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);
};

#endif
