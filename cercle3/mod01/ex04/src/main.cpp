#include "Sed.hpp"

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./sed <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	Sed sed(argv[1], argv[2], argv[3]);
	if (!sed.process())
	{
		std::cerr << "Error during processing." << std::endl;
		return (1);
	}

	return (0);
}
