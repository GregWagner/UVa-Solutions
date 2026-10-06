#include <iostream>
#include <cmath>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    double input;
    std::cin >> input;
    std::cout << std::round(input) << '\n';
}