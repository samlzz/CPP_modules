/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:05:17 by sliziard          #+#    #+#             */
/*   Updated: 2025/05/20 18:10:35 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie *newZombie(std::string name);
void	randomChump(std::string name);

int main()
{
	Zombie *z = newZombie("HeapZombie0");

	randomChump("StackZombie0");

	randomChump("StackZombie1");

	Zombie *zz = newZombie("HeapZombie1");
	zz->announce();
	delete zz;
	z->announce();
	delete z;

	std::cout << "Fin du programme" << std::endl;
	return 0;
}
