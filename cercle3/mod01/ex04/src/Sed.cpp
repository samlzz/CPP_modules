#include "Sed.hpp"

//* Constructors
Sed::Sed()
{
	std::cout << "Sed default constructor called" << std::endl;
}

Sed::Sed(
	const std::string &filename, const std::string &s1, const std::string &s2)
	: _filename(filename), _s1(s1), _s2(s2)
{
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
		this->_filename = other._filename;
		this->_s1		= other._s1;
		this->_s2		= other._s2;
	}
	return *this;
}

//* Methods

std::string Sed::replace_line(const std::string &line) const
{
	std::string res;
	size_t		start = 0;
	size_t		pos;

	while ((pos = line.find(this->_s1, start)) != std::string::npos)
	{
		res += line.substr(start, pos - start);
		res += this->_s2;
		start = pos + this->_s1.length();
	}
	res += line.substr(start);
	return (res);
}

bool Sed::process(void)
{
	std::ifstream in_file(this->_filename.c_str());
	if (!in_file.is_open())
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return (false);
	}
	std::ofstream out_file((this->_filename + ".replace").c_str());
	if (!out_file.is_open())
	{
		in_file.close();
		std::cerr << "Error: could not open output file." << std::endl;
		return (false);
	}

	std::string line;
	while (std::getline(in_file, line))
		out_file << replace_line(line) << std::endl;

	in_file.close();
	out_file.close();
	return (true);
}

//* Destructor

Sed::~Sed()
{
	std::cout << "Sed destructor called" << std::endl;
}
