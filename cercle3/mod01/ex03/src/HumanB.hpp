/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:24:24 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/14 15:24:25 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{

public:
	HumanB();
	HumanB(std::string name);
	HumanB(const HumanB &other);
	HumanB &operator=(const HumanB &other);
	~HumanB();

	void attack(void) const;

	void setWeapon(Weapon &weapon);

private:
	std::string _name;
	Weapon	   *_weapon;
};

#endif
