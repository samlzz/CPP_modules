#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl harl;
	switch (harl.get_index(argv[1]))
	{
	case 0:
		harl.complain("DEBUG");
		/* fallthrough */
	case 1:
		harl.complain("INFO");
		/* fallthrough */
	case 2:
		harl.complain("WARNING");
		/* fallthrough */
	case 3:
		harl.complain("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]"
				  << std::endl;
	}
	return 0;
}
