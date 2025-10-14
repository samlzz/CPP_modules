/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:35 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/04 14:31:21 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// *Constructors
Dog::Dog() : Animal("Dog"), _brain(new Brain)
{
#ifdef PRINT_CALLER
	std::cout << "Dog default constructor called" << std::endl;
#endif
}

Dog::Dog(const Dog &other) : Animal(other), _brain(new Brain(*other._brain))
{
#ifdef PRINT_CALLER
	std::cout << "Dog copy constructor called" << std::endl;
#endif
}

// *Destructor
Dog::~Dog()
{
#ifdef PRINT_CALLER
	std::cout << "Dog destructor called" << std::endl;
#endif
	delete this->_brain;
}

// operators
Dog &Dog::operator=(const Dog &other)
{
#ifdef PRINT_CALLER
	std::cout << "Dog assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		Animal::operator=(other);
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return *this;
}

//* Methods

void Dog::makeSound() const
{
	std::cout << "Woaaaf Woaaaf" << std::endl;
}
