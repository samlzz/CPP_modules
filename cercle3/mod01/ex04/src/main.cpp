/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:45:14 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/14 16:45:15 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

#define USAGE_ERR "Usage: ./ft_sed <filname> <s1> <s2>"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << USAGE_ERR << std::endl;
		return (1);
	}

	Sed sed(argv[1], argv[2], argv[3]);
	return (!sed.process());
}
