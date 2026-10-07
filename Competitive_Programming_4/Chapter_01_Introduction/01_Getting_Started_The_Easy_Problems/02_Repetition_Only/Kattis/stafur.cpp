#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    char c;
    std::cin >> c;

    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        std::cout << "Jebb\n";
    } else if (c == 'Y') {
        std::cout << "Kannski \n";
    } else {
        std::cout << "Neibb\n";
    }
}