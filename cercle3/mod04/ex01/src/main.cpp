#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/* int main()
{
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	j->makeSound();
	i->makeSound();

	delete j; //should not create a leak
	delete i;
	return 0;
}
 */

int main()
{
	const Animal *tab[10];
	size_t		  i = 0;

	while (i < 10)
	{
		if (i < 5)
			tab[i++] = new Dog;
		else
			tab[i++] = new Cat;
	}

	std::cout << std::endl;

	i = 0;
	while (i < 10)
	{
		delete tab[i++];
	}
}