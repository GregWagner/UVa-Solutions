#include <iostream>
#include <cmath>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    long a, b;
    while (std::cin >> a >> b) {
        std::cout << std::abs(a - b) << '\n';
    }
}