#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int numberOfActicles {};
    int impactFactor {};
    std::cin >> numberOfActicles >> impactFactor;
    std::cout << numberOfActicles * (impactFactor - 1) + 1 << '\n';
}