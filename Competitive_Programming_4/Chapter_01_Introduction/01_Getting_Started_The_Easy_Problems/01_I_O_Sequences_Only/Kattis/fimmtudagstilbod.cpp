#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int year{};
    std::cin >> year;
    std::cout << ((year <= 2020)
        ? 1000 : 1000 + (year - 2020) * 100) << '\n';
}