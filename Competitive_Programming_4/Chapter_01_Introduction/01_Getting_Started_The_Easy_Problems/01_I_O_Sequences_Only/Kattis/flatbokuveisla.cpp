#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int numberOfSlices{};
    int numberOfResidents{};
    std::cin >> numberOfSlices >> numberOfResidents;

    std::cout << numberOfSlices % numberOfResidents << '\n';
}