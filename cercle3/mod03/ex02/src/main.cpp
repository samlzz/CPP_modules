#include "FragTrap.hpp"

static void sep(const char* t){ std::cout << "\n=== " << t << " ===\n"; }

int main() {
  sep("Construction chain");
  FragTrap f("Fragonard"); // doit construire ClapTrap puis FragTrap

  sep("High Five");
  f.highFivesGuys();

  sep("Combat-like actions");
  f.attack("bad guy");     // hérite de ClapTrap::attack tel que tu l’as gardé
  f.takeDammage(42);
  f.beRepaired(10);

  sep("Copy tests");
  FragTrap g = f;          // copy ctor
  FragTrap h("Tmp");
  h = f;                   // assign

  sep("Energy drain");
  for (int i = 0; i < 105; ++i) f.attack("dummy"); // devrait s’épuiser

  sep("Destructors");
  return 0;
}

