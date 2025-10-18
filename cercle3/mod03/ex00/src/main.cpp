#include "ClapTrap.hpp"
#include <iostream>

static void sep(const char* t){ std::cout << "\n=== " << t << " ===\n"; }

int main() {
  sep("Constructors");
  ClapTrap a("Alice");
  ClapTrap b("Bob");
  ClapTrap c(a);
  c = b;

  sep("Basic actions");
  a.attack("Bob");
  b.takeDamage(3);
  b.beRepaired(2);

  sep("Energy depletion");
  for (int i = 0; i < 12; ++i) a.attack("Dummy");

  sep("Mixed");
  b.attack("Alice");
  a.takeDamage(4);
  a.beRepaired(1);

  sep("End of scope (destructors)");
  return 0;
}

