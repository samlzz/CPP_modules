#ifndef HARL_HPP
#define HARL_HPP

#include <stdint.h>
#include <string>

class Harl
{

public:
	Harl();
	Harl(std::string levels[4]);
	Harl(const Harl &other);
	Harl &operator=(const Harl &other);
	~Harl();

	void	complain(std::string level);
	int32_t get_index(const std::string &lvl) const;

private:
	std::string _lvls[4];

	void put_message(const std::string &lvl, const std::string &msg) const;
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
