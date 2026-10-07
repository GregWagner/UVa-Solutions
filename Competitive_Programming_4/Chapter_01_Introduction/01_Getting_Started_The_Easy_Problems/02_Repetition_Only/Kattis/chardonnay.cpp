#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int amount{};
    std::cin >> amount;

    if (amount >= 7) {
        std::cout << "7\n";
    } else if (amount > 0) {
        std::cout << amount + 1 << '\n';
    } else {
        std::cout << "0\n";
    }
}