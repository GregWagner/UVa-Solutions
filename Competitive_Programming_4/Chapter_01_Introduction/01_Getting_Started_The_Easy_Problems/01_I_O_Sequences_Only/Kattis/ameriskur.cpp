#include <iostream>
#include <iomanip>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int length{};
    std::cin >> length;
    std::cout << std::setprecision(20) << length * 0.09144 << '\n';
}