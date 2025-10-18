#include "ScavTrap.hpp"
// ClapTrap.hpp est inclus par ScavTrap.hpp

static void sep(const char* t){ std::cout << "\n=== " << t << " ===\n"; }

int main() {
  sep("Construction chain");
  ScavTrap s("Serena");    // doit montrer la chaîne ClapTrap -> ScavTrap

  sep("Stats check via actions");
  s.attack("target");      // override de ScavTrap
  s.guardGate();           // capacité spéciale

  sep("Copy/Assign");
  ScavTrap s2(s);          // copy ctor
  ScavTrap s3("Tmp");
  s3 = s;                  // assign

  sep("Energy usage");
  for (int i = 0; i < 55; ++i) s.attack("training dummy"); // finit par manquer d'énergie

  sep("Repairs and damage");
  s.takeDammage(30);
  s.beRepaired(20);        // -1 energy si possible

  sep("Destruction order");
  return 0;
}

