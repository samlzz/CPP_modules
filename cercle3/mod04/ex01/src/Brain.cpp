/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:31:24 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/04 14:31:24 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// *Constructors
Brain::Brain()
{
#ifdef PRINT_CALLER
	std::cout << "Brain default constructor called" << std::endl;
#endif
}

Brain::Brain(const Brain &other)
{
#ifdef PRINT_CALLER
	std::cout << "Brain copy constructor called" << std::endl;
#endif
	*this = other;
}

// *Destructor
Brain::~Brain()
{
#ifdef PRINT_CALLER
	std::cout << "Brain destructor called" << std::endl;
#endif
}

// operators
Brain &Brain::operator=(const Brain &other)
{
#ifdef PRINT_CALLER
	std::cout << "Brain assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		for (size_t i = 0; i < 100; ++i)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

//* Methods

// ...
