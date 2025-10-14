/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:15:12 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/12 21:27:21 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

//* Constructors
PhoneBook::PhoneBook() : _count(0)
{
	std::cout << "PhoneBook default constructor called" << std::endl;
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	std::cout << "PhoneBook copy constructor called" << std::endl;
	*this = other;
}

// operator
PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	std::cout << "PhoneBook assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_count = other._count;
		for (int32_t i = 0; i < MAX_CONTACTS; ++i)
			this->_contacts[i] = other._contacts[i];
	}
	return *this;
}

//* Helpers

static std::string formatField(const std::string &field)
{
	if (field.length() > COL_WIDTH)
		return field.substr(0, COL_WIDTH - 1) + ".";
	return (field);
}

static void _row_print(const std::string &idx, const std::string &fname,
	const std::string &lname, const std::string &nname)
{
	std::cout << std::setw(COL_WIDTH) << idx << "|" << std::setw(COL_WIDTH)
			  << fname << "|" << std::setw(COL_WIDTH) << lname << "|"
			  << std::setw(COL_WIDTH) << nname << std::endl;
}

//* Methods

void PhoneBook::_displayContacts(int32_t size) const
{
	std::ostringstream oss;

	_row_print("Index", "First Name", "Last Name", "Nickname");
	for (int32_t i = 0; i < size; ++i)
	{
		oss.str("");
		oss.clear();
		oss << i;
		_row_print(oss.str(), formatField(this->_contacts[i].getFirstName()),
			formatField(this->_contacts[i].getLastName()),
			formatField(this->_contacts[i].getNickname()));
	}
}

// public

void PhoneBook::addContact()
{
	int32_t index;

	index = this->_count % MAX_CONTACTS;
	if (!this->_contacts[index].ioFillFields())
		return;
	this->_count++;
	std::cout << "Contact added at index " << index << "." << std::endl;
}

void PhoneBook::searchContact() const
{
	int32_t max, i;

	max = (this->_count < MAX_CONTACTS) ? this->_count : MAX_CONTACTS;
	this->_displayContacts(max);
	std::cout << "Enter index to display full contact: ";
	std::cin >> i;

	if (std::cin.fail() || i < 0 || i >= max)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid index." << std::endl;
		return;
	}
	std::cin.ignore();
	this->_contacts[i].ioPrintFields();
}

//* Destructor

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook destructor called" << std::endl;
}
