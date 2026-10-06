#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string name;
    std::getline(std::cin, name);

    int a, b, result;
    std::cin >> a >> b >> result;

    // If the force user is a Jedi print JEDI. If the force user is a Sith print SITH. If you can’t determine whether they are Sith or Jedi print VEIT EKKI.
    // If the force user is a Jedi and the result is equal to a - b print JEDI. If the force user is a Sith and the result is equal to b - a print SITH. If neither of these conditions are true print VEIT EKKI.
    if (a < b) {
        std::cout << "JEDI\n";
    } else if (a > b) {
        std::cout << "SITH\n";
    } else {
        std::cout << "VEIT EKKI\n";
    }
}