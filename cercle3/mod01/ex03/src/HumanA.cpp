/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:49:45 by sliziard          #+#    #+#             */
/*   Updated: 2025/05/21 13:27:17 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//* Constructors

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA constructor called" << std::endl;
}

HumanA::HumanA(const HumanA &other) : _name(other._name), _weapon(other._weapon)
{
	std::cout << "HumanA copy constructor called" << std::endl;
}

// operators
HumanA &HumanA::operator=(const HumanA &other)
{
	std::cout << "HumanA assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_name	  = other._name;
		this->_weapon = other._weapon;
	}
	return *this;
}

//* Methods

void HumanA::attack() const
{
	std::cout << this->_name << " attack with their " << this->_weapon.getType()
			  << std::endl;
}

//* Destructor

HumanA::~HumanA()
{
	std::cout << "HumanA destructor called" << std::endl;
}
