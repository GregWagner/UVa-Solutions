#include <iostream>
#include <iomanip>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int ticks{};
    std::cin >> ticks;
    std::cout << std::setprecision(2) << std::fixed << (ticks / 4.0) << '\n';
}