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
	}
	return *this;
}

//* Methods

void Harl::put_message(const std::string &lvl, const std::string &msg) const
{
	std::cout << "[" << this->_lvls[this->get_index(lvl)] << "]: " << msg
			  << std::endl;
}

void Harl::debug(void)
{
	this->put_message("DEBUG",
		"I love having extra bacon for my "
		"7XL-double-cheese-triple-pickle-special-ketchup burger. I "
		"really do!");
}
void Harl::info(void)
{
	this->put_message("INFO",
		"I cannot believe adding extra bacon costs more money. You "
		"didn’t put enough bacon in my burger! If you did, I wouldn’t "
		"be asking for more!");
}
void Harl::warning(void)
{
	this->put_message("WARNING",
		"I think I deserve to have some extra bacon for free. I’ve "
		"been coming for	years, whereas you started working here "
		"just last month.");
}
void Harl::error(void)
{
	this->put_message(
		"ERROR", "This is unacceptable! I want to speak to the manager now");
}

int32_t Harl::get_index(const std::string &lvl) const
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

	idx = this->get_index(level);
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
