/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:45:17 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/14 16:45:18 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <string>

struct s_args
{
	std::string	filename;
	std::string	s1;
	std::string	s2;
};

class Sed
{
public:
	Sed(const Sed &other);
	Sed(const std::string &filename, const std::string &s1,
		const std::string &s2);
	Sed &operator=(const Sed &other);
	~Sed();

	bool process(void);

private:
	struct s_args	_args;
	std::ifstream	_in;
	std::ofstream	_out;
	bool			_stream_err;

	std::string replace_line(const std::string &line) const;
};

#endif
