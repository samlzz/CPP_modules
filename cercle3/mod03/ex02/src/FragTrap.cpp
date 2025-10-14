/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 08:27:41 by sliziard          #+#    #+#             */
/*   Updated: 2025/06/23 08:41:27 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// *Constructors
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
#ifdef PRINT_CALLER
	std::cout << "FragTrap default constructor called" << std::endl;
#endif
	this->_hit	   = 100;
	this->_energy  = 100;
	this->_dammage = 30;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
#ifdef PRINT_CALLER
	std::cout << "FragTrap copy constructor called" << std::endl;
#endif
}

// operators
FragTrap &FragTrap::operator=(const FragTrap &other)
{
#ifdef PRINT_CALLER
	std::cout << "FragTrap assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return (*this);
}

// *Methods

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a high five!"
			  << std::endl;
}

// *Destructor

FragTrap::~FragTrap()
{
#ifdef PRINT_CALLER
	std::cout << "FragTrap destructor called" << std::endl;
#endif
}
