/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 05:49:48 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/18 13:48:18 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <stdint.h>
#include <string>

#define PRINT_CALLER

class ClapTrap
{

public:
	ClapTrap(const std::string &name);
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);
	~ClapTrap();

	void attack(const std::string &target);
	void takeDamage(uint32_t amount);
	void beRepaired(uint32_t amount);

protected:
	std::string _name;
	uint32_t	_hit;
	uint32_t	_energy;
	uint32_t	_dammage;

	void print_act(const std::string &action, uint32_t amount,
		const std::string &suf) const;
	void print_act(const std::string &action) const;
	bool consume_energy(void);
};

#endif
