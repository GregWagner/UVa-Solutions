#include <iostream>

auto main() -> int {
    std::ios::sync_with_stdio(false);

    int improvementsSinceFrozen{};
    int improvementsPerYear{};
    std::cin >> improvementsSinceFrozen >> improvementsPerYear;
    std::cout << 2022 + (improvementsSinceFrozen / improvementsPerYear) << '\n';
}