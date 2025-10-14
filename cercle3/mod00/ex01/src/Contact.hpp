/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:17:52 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/12 21:17:53 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
public:
	Contact();
	Contact(std::string firstname, std::string lastname, std::string nickname,
		std::string phone_nb, std::string darkest_secret);
	Contact(const Contact &other);
	Contact &operator=(const Contact &other);
	~Contact();

	bool ioFillFields();
	void ioPrintFields() const;

	const std::string &getFirstName() const;
	const std::string &getLastName() const;
	const std::string &getNickname() const;
	const std::string &getPhone() const;
	const std::string &getSecret() const;

private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phone;
	std::string _secret;

	void _setContact(std::string firstname, std::string lastname,
		std::string nickname, std::string phone, std::string secret);
};

#endif
