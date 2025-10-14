/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:01:04 by sliziard          #+#    #+#             */
/*   Updated: 2025/05/20 18:09:02 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

//* Constructors
Zombie::Zombie()
{
	std::cout << "Zombie default constructor called" << std::endl;
}

Zombie::Zombie(std::string name)
{
	std::cout << "Zombie named constructor called for " << name << std::endl;
	this->_name = name;
}

Zombie::Zombie(const Zombie &other)
{
	std::cout << "Zombie copy constructor called" << std::endl;
	*this = other;
}

// operators
Zombie &Zombie::operator=(const Zombie &other)
{
	std::cout << "Zombie assignment operator called" << std::endl;
	if (this != &other)
		this->_name = other._name;
	return *this;
}

//* Methods

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

//* Destructor

Zombie::~Zombie()
{
	std::cout << "Zombie '" << this->_name << "' destructor called"
			  << std::endl;
}
