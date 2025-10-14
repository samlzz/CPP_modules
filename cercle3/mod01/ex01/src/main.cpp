/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:41:18 by sliziard          #+#    #+#             */
/*   Updated: 2025/05/20 18:42:13 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *zombieHorde(int N, std::string name);

int main()
{
	int		N	  = 5;
	Zombie *horde = zombieHorde(N, "Zed");

	for (int i = 0; i < N; ++i)
	{
		horde[i].announce();
		std::cout << std::endl;
	}

	delete[] horde;
	return 0;
}
