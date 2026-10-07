#include <iostream>
#include <string>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string input;
    std::getline(std::cin, input);
    std::cout << input << ' ' << input << ' ' << input << '\n';
}