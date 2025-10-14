/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:29 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/04 14:28:08 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// * Constructors
Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
#ifdef PRINT_CALLER
	std::cout << "Cat default constructor called" << std::endl;
#endif
}

Cat::Cat(const Cat &other) : Animal(other), _brain(new Brain(*other._brain))
{
#ifdef PRINT_CALLER
	std::cout << "Cat copy constructor called" << std::endl;
#endif
}
// * Destructor
Cat::~Cat()
{
#ifdef PRINT_CALLER
	std::cout << "Cat destructor called" << std::endl;
#endif
	delete this->_brain;
}

// operators
Cat &Cat::operator=(const Cat &other)
{
#ifdef PRINT_CALLER
	std::cout << "Cat assignment operator called" << std::endl;
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

void Cat::makeSound() const
{
	std::cout << "Miaouuuuuuw" << std::endl;
}
