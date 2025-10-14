/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:24:36 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/14 15:24:36 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
public:
	Weapon();
	Weapon(std::string type);
	Weapon(const Weapon &other);
	Weapon &operator=(const Weapon &other);
	~Weapon();

	std::string getType(void) const;
	void		setType(std::string type);

private:
	std::string _type;
};

#endif
