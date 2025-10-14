#ifndef SED_HPP
#define SED_HPP

#include <fstream>
#include <iostream>
#include <string>

class Sed
{
public:
	Sed();
	Sed(const Sed &other);
	Sed(const std::string &filename, const std::string &s1,
		const std::string &s2);
	Sed &operator=(const Sed &other);
	~Sed();

	bool process(void);

private:
	std::string _filename;
	std::string _s1;
	std::string _s2;

	std::string replace_line(const std::string &line) const;
	bool		open_fstream(const std::string &src) const;
};

#endif
