/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 21:21:24 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/12 21:21:24 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <limits>

int main()
{
	PhoneBook	pb;
	std::string input;

	while (true)
	{
		std::cout << "Enter command (ADD / SEARCH / EXIT): ";
		if (!std::getline(std::cin, input))
		{
			if (std::cin.eof())
				break;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.searchContact();
		else if (input == "EXIT")
			break;
		else
			std::cout << "Unknown command." << std::endl;
		if (std::cin.eof())
			break;
		std::cout << std::endl;
	}
	return 0;
}
