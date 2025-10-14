/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliziard <sliziard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:45:12 by sliziard          #+#    #+#             */
/*   Updated: 2025/10/14 16:45:12 by sliziard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

//* Constructors

Sed::Sed(
	const std::string &filename, const std::string &s1, const std::string &s2)
	: _args((struct s_args) {filename, s1, s2}),
	_in(filename.c_str()),
	_out()
{
	std::cout << "Sed constructor called" << std::endl;
	if (_in.is_open())
		_out.open((filename + ".replace").c_str());
	_stream_err = !_in.is_open() || !_out.is_open();
}

Sed::Sed(const Sed &other)
{
	std::cout << "Sed copy constructor called" << std::endl;
	*this = other;
}

// operators
Sed &Sed::operator=(const Sed &other)
{
	std::cout << "Sed assignment operator called" << std::endl;
	if (this != &other)
	{
		_args = other._args;
	}
	return *this;
}

//* Methods

std::string Sed::replace_line(const std::string &line) const
{
	std::string res;
	size_t		start = 0;
	size_t		pos;

	while ((pos = line.find(_args.s1, start)) != std::string::npos)
	{
		res += line.substr(start, pos - start);
		res += _args.s2;
		start = pos + _args.s1.length();
	}
	res += line.substr(start);
	return (res);
}

bool Sed::process(void)
{
	if (_stream_err)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (false);
	}

	std::string line;
	while (std::getline(_in, line))
		_out << replace_line(line) << std::endl;

	return (true);
}

//* Destructor

Sed::~Sed()
{
	std::cout << "Sed destructor called" << std::endl;
	if (_in.is_open())
		_in.close();
	if (_out.is_open())
		_out.close();
}
