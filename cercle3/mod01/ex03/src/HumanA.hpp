/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:32:00 by sliziard          #+#    #+#             */
/*   Updated: 2025/05/21 13:27:21 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{

public:
	HumanA(std::string name, Weapon &weapon);
	HumanA(const HumanA &other);
	HumanA &operator=(const HumanA &other);
	~HumanA();

	void attack(void) const;

private:
	std::string _name;
	Weapon	   &_weapon;
};

#endif
