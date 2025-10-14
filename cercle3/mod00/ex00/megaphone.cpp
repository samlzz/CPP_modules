/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 16:59:49 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/11 17:06:23 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

#define NO_PARAM_MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << NO_PARAM_MSG << std::endl;
		return (0);
	}
	int i, j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
			std::cout << static_cast<char>(std::toupper((argv[i][j++])));
		i++;
	}
	std::cout << std::endl;
	return (0);
}
