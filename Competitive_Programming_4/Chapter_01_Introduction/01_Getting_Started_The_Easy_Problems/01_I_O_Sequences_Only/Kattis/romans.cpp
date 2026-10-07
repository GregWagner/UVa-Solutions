#include <iostream>
#include <cmath>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    double miles{};
    std::cin >> miles;

    std::cout << (int)std::round(miles * 5280 / 4.854);
}