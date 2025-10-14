/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:16:39 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/12 21:23:46 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <limits>
#include <stdint.h>

//* Constructors

Contact::Contact()
{
	std::cout << "Contact default constructor called" << std::endl;
}

Contact::Contact(const Contact &other)
{
	std::cout << "Contact copy constructor called" << std::endl;
	*this = other;
}

Contact::Contact(std::string firstname, std::string lastname,
	std::string nickname, std::string phone_nb, std::string darkest_secret)
{
	this->_setContact(firstname, lastname, nickname, phone_nb, darkest_secret);
}

// operator
Contact &Contact::operator=(const Contact &other)
{
	std::cout << "Contact assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_setContact(other.getFirstName(), other.getLastName(),
			other.getNickname(), other.getPhone(), other.getSecret());
	}
	return *this;
}

//* Methods

void Contact::_setContact(std::string firstname, std::string lastname,
	std::string nickname, std::string phone, std::string secret)
{
	this->_firstname = firstname;
	this->_lastname	 = lastname;
	this->_nickname	 = nickname;
	this->_phone	 = phone;
	this->_secret	 = secret;
}

// Public

bool Contact::ioFillFields()
{
	const char	*labels[5] = {"first name", "last name", "nickname",
		 "phone number", "darkest secret"};
	std::string *fields[5] = {&this->_firstname, &this->_lastname,
		&this->_nickname, &this->_phone, &this->_secret};
	int32_t		 i;

	for (i = 0; i < 5; ++i)
	{
		std::cout << "Enter " << labels[i] << ": ";
		if (!std::getline(std::cin, *fields[i]))
		{
			if (std::cin.eof())
			{
				std::cerr << "\nInput canceled (EOF)." << std::endl;
				return false;
			}
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			i--;
			continue;
		}
		if (fields[i]->empty())
		{
			std::cerr << "Field '" << labels[i] << "' must not be empty."
					  << std::endl;
			return false;
		}
	}
	return true;
}

void Contact::ioPrintFields() const
{
	std::cout << "First name: " << this->_firstname << std::endl;
	std::cout << "Last name: " << this->_lastname << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone: " << this->_phone << std::endl;
	std::cout << "Secret: " << this->_secret << std::endl;
}

// getter
const std::string &Contact::getFirstName() const
{
	return this->_firstname;
}
const std::string &Contact::getLastName() const
{
	return this->_lastname;
}
const std::string &Contact::getNickname() const
{
	return this->_nickname;
}
const std::string &Contact::getPhone() const
{
	return this->_phone;
}
const std::string &Contact::getSecret() const
{
	return this->_secret;
}

//* Destructor

Contact::~Contact()
{
	std::cout << "Contact destructor called" << std::endl;
}
