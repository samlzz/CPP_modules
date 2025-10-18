/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 05:49:46 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/18 13:48:29 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

// *Constructors
ClapTrap::ClapTrap(const std::string &name)
	: _name(name), _hit(10), _energy(10), _dammage(0)
{
#ifdef PRINT_CALLER
	std::cout << "ClapTrap default constructor called" << std::endl;
#endif
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
#ifdef PRINT_CALLER
	std::cout << "ClapTrap copy constructor called" << std::endl;
#endif
	*this = other;
}

// operators
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
#ifdef PRINT_CALLER
	std::cout << "ClapTrap assignment operator called" << std::endl;
#endif
	if (this != &other)
	{
		this->_name	   = other._name;
		this->_hit	   = other._hit;
		this->_energy  = other._energy;
		this->_dammage = other._dammage;
	}
	return (*this);
}

// *Methods

void ClapTrap::attack(const std::string &target)
{
	if (!this->consume_energy())
		return;
	this->print_act("attacks " + target + ", causing", this->_dammage,
		"points of damage !");
}
void ClapTrap::takeDamage(uint32_t amount)
{
	this->_hit -= amount;
	this->print_act("take", amount, "of damage.");
}
void ClapTrap::beRepaired(uint32_t amount)
{
	if (!this->consume_energy())
		return;
	this->_hit += amount;
	this->print_act("repare of", amount, "hit points.");
}

// private
bool ClapTrap::consume_energy(void)
{
	if (this->_energy == 0)
	{
		this->print_act("no energy left anymore.");
		return (false);
	}
	this->_energy--;
	return (true);
}

void ClapTrap::print_act(
	const std::string &action, uint32_t amount, const std::string &suf) const
{
	std::cout << "ClapTrap " << this->_name << " " << action << " " << amount
			  << " " << suf << std::endl;
}
void ClapTrap::print_act(const std::string &action) const
{
	std::cout << "ClapTrap " << this->_name << " " << action << std::endl;
}

// *Destructor

ClapTrap::~ClapTrap()
{
#ifdef PRINT_CALLER
	std::cout << "ClapTrap destructor called" << std::endl;
#endif
}
