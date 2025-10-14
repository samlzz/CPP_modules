#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>

#define PRINT_CALLER

class AMateria
{

protected:
	std::string _type;

public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	~AMateria();

	AMateria &operator=(const AMateria &other);

	std::string const &getType() const;

	virtual AMateria *clone() const = 0;
	virtual void	  use(ICharacter &target);
};

#endif
