#include <iostream>
#include <iomanip>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int percentage{};
    std::cin >> percentage;

    std::cout << std::setprecision(10) << std::fixed
        << 100.0 / percentage << '\n'
        << 100.0 / (100 - percentage) << '\n';
}