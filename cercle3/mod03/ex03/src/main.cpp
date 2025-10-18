#include "DiamondTrap.hpp"

static void sep(const char* t){ std::cout << "\n=== " << t << " ===\n"; }

int main() {
  sep("Construction (virtual inheritance)");
  DiamondTrap d("JeanMich");  // ClapTrap name doit être "JeanMich_clap_name"

  sep("Who am I?");
  d.whoAmI();                 // affiche son nom et le ClapTrap::_name

  sep("Attack dispatch (ScavTrap::attack)");
  d.attack("Jean-René");      // doit utiliser l’attack de ScavTrap (using ScavTrap::attack)

  sep("Inherited stats usage");
  d.takeDammage(25);          // utilise l’unique ClapTrap sous-jacent
  d.beRepaired(10);

  sep("Copy/Assign");
  DiamondTrap e(d);           // copy ctor
  DiamondTrap f("Temp");
  f = d;                      // assign
  e.whoAmI();
  f.attack("training dummy");

  sep("Energy exhaustion quick check");
  for (int i = 0; i < 60; ++i) d.attack("dummy"); // épuiser l’énergie héritée côté ScavTrap

  sep("Destruction order");
  return 0;
}

