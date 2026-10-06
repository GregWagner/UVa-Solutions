#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int beers, lemonades;
    std::cin >> beers >> lemonades;

    std::cout << 2 * std::min(beers, lemonades) << '\n';
}