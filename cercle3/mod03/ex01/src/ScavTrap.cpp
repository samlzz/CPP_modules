/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 05:49:33 by sliziard          #+#    #+#             */
/*   Updated: 2025/06/23 06:00:50 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//* Constructors
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
#ifdef PRINT_CALLER
	std::cout << "ScavTrap default constructor called" << std::endl;
#endif
	this->_hit	   = 100;
	this->_energy  = 50;
	this->_dammage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
#ifdef PRINT_CALLER
	std::cout << "ScavTrap copy constructor called" << std::endl;
#endif
}

// operators
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
#ifdef PRINT_CALLER
	std::cout << "ScavTrap assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

//* Methods

void ScavTrap::attack(const std::string &target)
{
	if (!this->consume_energy())
		return;
	this->print_act("ScavTrap attacks " + target + ", causing", this->_dammage,
		"points of damage!");
}

void ScavTrap::guardGate()
{
	this->print_act("is now in Gate Keeper mode.");
}

//* Destructor

ScavTrap::~ScavTrap()
{
#ifdef PRINT_CALLER
	std::cout << "ScavTrap destructor called" << std::endl;
#endif
}
