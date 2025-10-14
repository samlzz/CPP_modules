#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl log;

	for (int i = 0; i < argc; i++)
		log.complain(argv[i]);
}