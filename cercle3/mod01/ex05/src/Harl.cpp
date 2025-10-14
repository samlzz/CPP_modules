/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:45:06 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/14 17:35:59 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

//* Constructors
Harl::Harl()
{
	_lvls[0] = "DEBUG";
	_lvls[1] = "INFO";
	_lvls[2] = "WARNING";
	_lvls[3] = "ERROR";
	std::cout << "Harl default constructor called" << std::endl;
}

Harl::Harl(const Harl &other)
{
	std::cout << "Harl copy constructor called" << std::endl;
	*this = other;
}

// operators
Harl &Harl::operator=(const Harl &other)
{
	std::cout << "Harl assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int32_t i = 0; i < 4; i++)
		{
			this->_lvls[i] = other._lvls[i];
		}
	}
	return *this;
}

//* Methods

void Harl::put_message(const std::string &lvl, const std::string &msg) const
{
	std::cout << "[" << lvl << "]: " << msg << std::endl;
}

void Harl::debug(void)
{
	this->put_message(_lvls[0],
		"I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-ketchup burger. I "
		"really do!");
}
void Harl::info(void)
{
	this->put_message(_lvls[1],
		"I cannot believe adding extra bacon costs more money. You "
		"didn’t put enough bacon in my burger! If you did, I wouldn’t "
		"be asking for more!");
}
void Harl::warning(void)
{
	this->put_message(_lvls[2],
		"I think I deserve to have some extra bacon for free. I’ve "
		"been coming for	years, whereas you started working here "
		"just last month.");
}
void Harl::error(void)
{
	this->put_message(_lvls[3],
		"This is unacceptable! I want to speak to the manager now");
}

int32_t Harl::get_lvl_index(const std::string &lvl) const
{
	for (int32_t i = 0; i < 4; i++)
	{
		if (this->_lvls[i] == lvl)
			return (i);
	}
	return (-1);
}

void Harl::complain(std::string level)
{
	int32_t idx;
	void (Harl::*functions[])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	idx = this->get_lvl_index(level);
	if (idx != -1)
		(this->*functions[idx])();
	else
		std::cout << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
}

//* Destructor

Harl::~Harl()
{
	std::cout << "Harl destructor called" << std::endl;
}
