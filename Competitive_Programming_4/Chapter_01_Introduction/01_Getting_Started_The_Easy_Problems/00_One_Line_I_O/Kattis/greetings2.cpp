#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    std::string greeting;
    std::cin >> greeting;

    int count{ 2 * (greeting.length() - 2) };
    std::cout << "h" + std::string(count, 'e') + "y\n";
}