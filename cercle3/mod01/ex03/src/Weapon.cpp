/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:24:33 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/14 15:24:33 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//* Constructors
Weapon::Weapon()
{
	std::cout << "Weapon default constructor called" << std::endl;
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::Weapon(const Weapon &other)
{
	std::cout << "Weapon copy constructor called" << std::endl;
	*this = other;
}

// operators
Weapon &Weapon::operator=(const Weapon &other)
{
	std::cout << "Weapon assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other.getType();
	}
	return *this;
}

//* Methods

std::string Weapon::getType(void) const
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
}

//* Destructor

Weapon::~Weapon()
{
	std::cout << "Weapon destructor called" << std::endl;
}
