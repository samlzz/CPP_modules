/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:14:54 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/12 21:24:39 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <stdint.h>

#define MAX_CONTACTS 8
#define COL_WIDTH 10

class PhoneBook
{
public:
	PhoneBook();
	PhoneBook(const PhoneBook &other);
	PhoneBook &operator=(const PhoneBook &other);
	~PhoneBook();

	void addContact();
	void searchContact() const;

private:
	Contact _contacts[MAX_CONTACTS];
	int32_t _count;

	void _displayContacts(int32_t size) const;
};

#endif
