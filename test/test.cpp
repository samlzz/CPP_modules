#include <cstdio>
#include <iostream>
#include <istream>
#include <limits>
#include <ostream>
#include <string>

int main() {
  std::string input;

  while (true) {
    std::cout << "Enter input: " << std::flush;

    if (!std::getline(std::cin, input)) {
      if (std::cin.eof()) {
        std::cout << "EOF pressed\n";
        std::cin.clear(); // on efface eof/fail
        std::clearerr(stdin);
        // NE PAS faire ignore() ici, sinon on re-déclenche EOF
      } else {
        // autre erreur : on nettoie et on purge la ligne courante
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      }
      continue;
    }

    std::cout << "gl return: true\n";
    std::cout << "input: " << input << "\n";
  }
}
