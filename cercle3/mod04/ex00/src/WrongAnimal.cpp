/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:16:35 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/03 18:26:15 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// * Constructors
WrongAnimal::WrongAnimal() : _type("Wrong generic animal")
{
#ifdef PRINT_CALLER
	std::cout << "WrongAnimal default constructor called" << std::endl;
#endif
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
#ifdef PRINT_CALLER
	std::cout << "WrongAnimal parameters constructor called" << std::endl;
#endif
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
#ifdef PRINT_CALLER
	std::cout << "WrongAnimal copy constructor called" << std::endl;
#endif
	*this = other;
}

// operators
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
#ifdef PRINT_CALLER
	std::cout << "WrongAnimal assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

// * Destructor
WrongAnimal::~WrongAnimal()
{
#ifdef PRINT_CALLER
	std::cout << "WrongAnimal destructor called" << std::endl;
#endif
}

//* Methods

std::string WrongAnimal::getType() const
{
	return (this->_type);
}

void WrongAnimal::makeSound() const
{
	std::cout << "...no wrong sound idea" << std::endl;
}
