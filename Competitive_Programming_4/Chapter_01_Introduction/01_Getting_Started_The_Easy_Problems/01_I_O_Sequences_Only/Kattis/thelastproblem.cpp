#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string name;
    std::getline(std::cin, name);
    std::cout << "Thank you, " << name << ", and farewell!\n";
}