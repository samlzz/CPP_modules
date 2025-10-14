/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:24:29 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/03 18:19:05 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// * Constructors
Cat::Cat() : Animal("Cat")
{
#ifdef PRINT_CALLER
	std::cout << "Cat default constructor called" << std::endl;
#endif
}

Cat::Cat(const Cat &other) : Animal(other)
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
	}
	return *this;
}

//* Methods

void Cat::makeSound() const
{
	std::cout << "Miaouuuuuuw" << std::endl;
}
