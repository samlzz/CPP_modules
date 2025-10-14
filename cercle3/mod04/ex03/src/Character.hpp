/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 16:00:28 by sliziard          #+#    #+#             */
/*   Updated: 2025/07/04 16:46:45 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ASlot.hpp"
#include "ICharacter.hpp"
#include <iostream>

#define PRINT_CALLER

class Character : public ICharacter
{
private:
	std::string _name;
	ASlot		_inventory;

public:
	Character();
	Character(std::string const &name);
	Character(const Character &other);
	~Character();

	Character &operator=(const Character &other);

	std::string const &getName() const;
	void			   equip(AMateria *m);
	void			   unequip(int idx);
	void			   use(int idx, ICharacter &target);
};

#endif
