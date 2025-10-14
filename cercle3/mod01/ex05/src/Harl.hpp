/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:45:02 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/14 16:45:03 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <stdint.h>

class Harl
{

public:
	Harl();
	Harl(std::string levels[4]);
	Harl(const Harl &other);
	Harl &operator=(const Harl &other);
	~Harl();

	void complain(std::string level);

private:
	std::string _lvls[4];

	int32_t get_lvl_index(const std::string &lvl) const;
	void	put_message(const std::string &lvl, const std::string &msg) const;
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif
