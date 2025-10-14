/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:22 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/03 18:22:36 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// *Constructors
Animal::Animal() : _type("generic animal")
{
#ifdef PRINT_CALLER
	std::cout << "Animal default constructor called" << std::endl;
#endif
}

Animal::Animal(std::string type) : _type(type)
{
#ifdef PRINT_CALLER
	std::cout << "Animal parameters constructor called" << std::endl;
#endif
}

Animal::Animal(const Animal &other)
{
#ifdef PRINT_CALLER
	std::cout << "Animal copy constructor called" << std::endl;
#endif
	*this = other;
}
// * Destructor
Animal::~Animal()
{
#ifdef PRINT_CALLER
	std::cout << "Animal destructor called" << std::endl;
#endif
}

// operators
Animal &Animal::operator=(const Animal &other)
{
#ifdef PRINT_CALLER
	std::cout << "Animal assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

//* Methods

std::string Animal::getType() const
{
	return (this->_type);
}

void Animal::makeSound() const
{
	std::cout << "...no sound idea" << std::endl;
}
